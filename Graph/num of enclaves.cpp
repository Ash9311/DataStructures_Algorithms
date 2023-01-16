//https://leetcode.com/problems/number-of-enclaves/description/

//traverse through the boundary of grid and perform bfs on element with value '1' and mark them as visited. so all the cell with value '1' connected to boundary '1'
//will be marked visited. In the end count of cells which has value 1 and not visited is our answer.
//TC, SC - O(n*m)

class Solution {

private:
void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,int delRow[],int delCol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});

    while(!q.empty()){
        int Currrow = q.front().first;
        int Currcol = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = Currrow + delRow[i];
            int ncol = Currcol + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        //to track neighbours we use delta method
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
       //traverse first and last row
       for(int j=0;j<m;j++){
           if(grid[0][j]==1 && !vis[0][j]){
               bfs(0,j,grid,vis,delRow,delCol);
           }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
               bfs(n-1,j,grid,vis,delRow,delCol);
           }
       }

       //travers first and last col
       for(int i=0;i<n;i++){
           if(grid[i][0]==1 && !vis[i][0]){
               bfs(i,0,grid,vis,delRow,delCol);
           }
           if(grid[i][m-1]==1 && !vis[i][m-1]){
               bfs(i,m-1,grid,vis,delRow,delCol);
           }
       }
       //since all are processed.count of cells which has value 1 and not visited is our answer
        int count = 0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==1 && !vis[i][j]){
                   count++;
               }
           }
       }
       return count;
    }
};
