// User function Template for C++
//first traverse the boundaries of the 2d matrix and apply DFS on those elements which are 'O' and not visisted
//so all the neighbouring O's will be marked as visited. and this will help us deduce our ans.
//in the end just turn those 'O' into 'X' which are not visited

//TC - O(n*m)*4 + O(n)+O(m)
//       DFS        boundaries running
 class Solution{
    
    private:
    void dfs(int row,int col,vector<vector<char>> &mat,vector<vector<int>> &vis,int delRow[],int delCol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        //check for top,right,bottom,left
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && mat[nRow][nCol]=='O'){
                dfs(nRow,nCol,mat,vis,delRow,delCol);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        //traverse first row and last row
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j]){
                dfs(0,j,mat,vis,delRow,delCol);
            }
            
            //last row
            if(mat[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,mat,vis,delRow,delCol);
            }
        }
        //traverse first col and last col
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(i,0,mat,vis,delRow,delCol);
            }
            
            //last row
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,mat,vis,delRow,delCol);
            }
        }
        
        //turn those 'O' into 'X' which are not visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
