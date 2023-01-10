//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
//traverse through the grid. if a land is found i.e '1' increment the count and perform dfs on it. so all the neighbouring lands will be covered with
//count of 1.
class Solution {
    
    private:
void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){ //process the queue elements
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverse in the neighbours and mark them  if its a land
        for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
          int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

-----------------------------------------
    
    
    

//https://leetcode.com/problems/number-of-islands/submissions/

class Solution {
    
    public int m;
    public int n;
    public int numIslands(char[][] grid) {
        n = grid.length;
        int count=0;
        m = grid[0].length;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                DFS(i,j,grid);
                count++;
                }
            }
        }
        return count;
    }
    
    public void DFS(int i,int j,char[][] grid){
        if(i<0 || j<0 || i>=n || j>=m ||grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        DFS(i+1,j,grid);
        DFS(i-1,j,grid);
        DFS(i,j+1,grid);
        DFS(i,j-1,grid);
    }
}
