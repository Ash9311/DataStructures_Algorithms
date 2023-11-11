//https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
int maxx = 0;
    void bfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        int count = 1;
        vis[i][j]=1;
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};

        while(!q.empty()){ //process each cell
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //explore the neighbours
            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){  //validate
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    count++;
                } 
            }
        }
        maxx = max(maxx,count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){ //iterate through grid and if its a land then apply bfs
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){ 
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return maxx;
    }
};
