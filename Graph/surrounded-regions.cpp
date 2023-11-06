//https://leetcode.com/problems/surrounded-regions/

// User function Template for C++
//first traverse the boundaries of the 2d matrix and apply DFS on those elements which are 'O' and not visisted
//so all the neighbouring O's will be marked as visited. and this will help us deduce our ans.
//in the end just turn those 'O' into 'X' which are not visited

//TC - O(n*m)*4 + O(n)+O(m)
//       DFS        boundaries running
class Solution {
public:

void dfs(int row,int col, vector<vector<char>> &board,vector<vector<int>> &vis,int delRow[],int delCol[]){
    vis[row][col] =1; //mark as visited
    int n= board.size();
    int m = board[0].size();

    //check for neighbours
    for(int i=0;i<4;i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && board[nRow][nCol]=='O'){ //validate the cell
            dfs(nRow,nCol,board,vis,delRow,delCol);
        }
    }
}

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        //traverse first & last row
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis,delRow,delCol);
            }
             if(board[n-1][i]=='O' && !vis[n-1][i]){
                 dfs(n-1,i,board,vis,delRow,delCol);
            }
        }

         //traverse first & last col
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,delRow,delCol);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,delRow,delCol);
            }
        }

        //flip those 'O' int 'X' wch r not visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j] = 'X';
            }
        }

    }
};
