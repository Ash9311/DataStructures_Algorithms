//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

//traverse through all elements of grid and push element with value '1' to the queue along with index. do bfs on each
//element of the queue and return the distance which was noted
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        //{{row,col},dist}
        //O(n*m)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ //traverse through all elements of grid and push element with value '1' to the queue along with index 
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    dist[i][j]=0; //since the value is 1 itself
                    q.push({{i,j},0});
                }
            }
        }
        int delRow[] = {-1,0,+1,0};  //to find the neighbouring elements
        int delCol[] = {0,+1,0,-1};
        //O(n*m*4)
        while(!q.empty()){ //process each element of the queue
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps; //note the distance
            for(int i=0;i<4;i++){ //find its neighbours
                int nRow = row+delRow[i]; //neighbouring row and col
                int nCol = col + delCol[i];
                if(nRow>=0 and nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol]){ //validate the neighbour and push it to queue + visited
                    vis[nRow][nCol] = 1;
                    q.push({{nRow,nCol},steps+1});
                }
            }
        }
        return dist;
	}
};
