//traverse through entire grid and perform dfs on '1'. declare a vector of pair to store coordinates. subtract from
//origin to get find similar pattern. and store them in a set of vector pair and return the size as the answer

//tc- O(n*m*log(n*m) + (n*m*4))
class Solution {
    
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,
    vector<pair<int,int>> &ds,int rowO,int colO){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};
        ds.push_back({row-rowO,col-colO}); //subtract coordinates from origin so that u get common result for same pattern of island                 
        //check for top,right,bottom,left
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1){
                dfs(nRow,nCol,grid,vis,ds,rowO,colO);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                     vector<pair<int,int>> ds; //if this is declared outside then ul get wrong ans
                    dfs(i,j,grid,vis,ds,i,j);
                     st.insert(ds);
            }
        }
    }
    return st.size();
    }
};
