//https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

//create adj list. declare min heap. process each element of min heap. if shorter distance is found then
//update distance. once distance n is found. check for the path by refering parent vector
//TC - O(eLogV)
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]}); //first 2 are neighbouring nodes and 3rd is weight
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min heap
        vector<int> dist(n+1,1e9), parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i; //mark parent as same node initially
        }
        dist[1] = 0; //dist of 1 is always 0. its given
        
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second; //edgeWeight
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis+edW,adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        //v found the distance ,now get the path
        if(dist[n]==1e9){
            return {-1};
        }
        vector<int> path;
        int node = n;
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};
