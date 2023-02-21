//https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

//create a queue of pair for distance and coordinates. insert source first and use delta method to 
//track neighbours. find the shortest distance. if destination is found in the process return the ans
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
         if(source.first==destination.first && source.second==destination.second) { //source is dest case
             return 0; 
        }
        queue<pair<int,pair<int,int>>> q; //{dist,{row,col}}
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        int dr[] = {-1,0,1,0}; //use delta method to get neighbours since adj matrix isnt given
        int dc[] = {0,1,0,-1};
        while(!q.empty()){ //process each element of the queue
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<4;i++){ //check for neighbours
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dis+1<dist[newr][newc]){
                    dist[newr][newc]=dis+1;
                    if(newr==destination.first && newc==destination.second){ //got our ans
                        return dis+1;
                    }
                    q.push({1+dis,{newr,newc}});
                }
            }
        }
       
        return -1;
    }
};
