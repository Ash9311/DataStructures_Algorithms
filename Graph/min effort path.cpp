//https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
//initialize a min heap with difference , coordinates,source dist. create delta row,col since adj isnt given. the
//first time where u reach destination in the process is the ans
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        //E log V
        // n*m*4*log(n*m)
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row==n-1 && col==m-1){
                return diff;  //since we are using min heap the first destination we get is the min.
            }
            
            for(int i=0;i<4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int newEfforts = max(abs(heights[row][col]-heights[newr][newc]),diff); //diff is taken as max one considered in that path
                    if(newEfforts<dist[newr][newc]){
                    dist[newr][newc]=newEfforts; //update and push the new data to the pq
                    pq.push({newEfforts,{newr,newc}});
                }
            }
        }
    }
        return 0;
    }
};
