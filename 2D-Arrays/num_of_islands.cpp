//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/#
//iterate through each char in the 2d vector mark visited ones and visited and apply DFS

class Solution {
  public:
  
  void dfs(vector<vector<char>>& grid,int i,int j,int row,int col){
      if(i<0 or i>=row or j<0 or j>=col){
          return;
      }
      if(grid[i][j]!='1'){
          return;
      }
      grid[i][j]='V';// so that v get to know its visited
      dfs(grid,i+1,j,row,col); //trace all directions(diagonal included)
      dfs(grid,i-1,j,row,col);
      dfs(grid,i,j-1,row,col);
      dfs(grid,i,j+1,row,col);
      dfs(grid,i+1,j+1,row,col);
      dfs(grid,i-1,j+1,row,col);
      dfs(grid,i-1,j-1,row,col);
      dfs(grid,i+1,j-1,row,col);
  }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        int count=0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){ // grid[i][j] value will be changed for future ones in the recursive dfs call 
                    dfs(grid,i,j,row,col);
                    count++;
                }
            }
        }
        return count;
        
