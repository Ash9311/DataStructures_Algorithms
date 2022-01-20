//https://leetcode.com/problems/max-area-of-island/
class Solution {
    
    public: int maxx=0;
public:
    
    void bfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &vis,int n,int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        int count=1;
        vis[i][j]=1;
    
        int dx[] = {0,0,1,-1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int idx=0;idx<4;idx++){
                int newi=i+dx[idx];
                int newj=j+dy[idx];
                
                if(newi>=0 and newj>=0 and newi<n and newj<m and !vis[newi][newj] and grid[newi][newj]){
                    q.push({newi,newj});
                    vis[newi][newj]=1;
                    count++;
                }
            }
            
        }
       maxx=max(maxx,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    bfs(grid,i,j,vis,n,m);
                }
            }
        }
        return maxx;
    }
};
