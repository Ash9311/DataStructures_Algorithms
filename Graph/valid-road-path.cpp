//https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
public:

    bool is_valid(int i,int j,vector<vector<int> > &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        return 1;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(0,0,vis,grid);
        return vis[n-1][m-1];// if last grid is visited then its true
    }

    void dfs(int i,int j, vector<vector<bool>> &vis,vector<vector<int>>& grid){
        if(vis[i][j]) return;
        vis[i][j]=1;
        int up,down,left,right; 
        up=down=left=right=0;
        if(grid[i][j]==1) left=right=1; //mark as 1 if connects as per diagram
        if(grid[i][j]==2) up=down=1;
        if(grid[i][j]==3) left=down=1;
        if(grid[i][j]==4) down=right=1;
        if(grid[i][j]==5) left=up=1;
        if(grid[i][j]==6) up=right=1;   

        if(up){ // check if current grid connects neighbouring . if yes explore the paths using DFS
            int dx=i-1,dy=j;
            if(is_valid(dx,dy,grid) && (grid[dx][dy]==2 ||grid[dx][dy]==3 || grid[dx][dy]==4 ) ){
                dfs(dx,dy,vis,grid);
            }
        }
         if(down){
            int dx=i+1,dy=j;
            if(is_valid(dx,dy,grid) && (grid[dx][dy]==2 ||grid[dx][dy]==5 || grid[dx][dy]==6 ) ){
                dfs(dx,dy,vis,grid);
            }
        }
         if(left){
            int dx=i,dy=j-1;
            if(is_valid(dx,dy,grid) && (grid[dx][dy]==1 ||grid[dx][dy]==4 || grid[dx][dy]==6 ) ){
                dfs(dx,dy,vis,grid);
            }
        }
         if(right){
            int dx=i,dy=j+1;
            if(is_valid(dx,dy,grid) && (grid[dx][dy]==1 ||grid[dx][dy]==3 || grid[dx][dy]==5 ) ){
                dfs(dx,dy,vis,grid);
            }
        }
    }
};
