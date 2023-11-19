//https://leetcode.com/problems/cheapest-flights-within-k-
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        //[[{neigh1,neigh2}]]    since there can only be 2 neighbours to a node i.e from and to
        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]}); //flight[0] acts as index
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        //[node,cost]
        vector<int> minCost(n,INT_MAX);
        int stops = 0;
        while(!q.empty() && stops<=k){
            int size = q.size();
            while(size--){ //process currNode and find its neighbours
                int currNode = q.front().first;
                int cost = q.front().second;
                q.pop();
                for(auto& [neighbour,price]:adj[currNode]){ //explore curr node's neighbours
                    if(price+cost<minCost[neighbour]){ // update if found min
                        minCost[neighbour] = price+cost;
                        q.push({neighbour,minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst]==INT_MAX) return -1;
        return minCost[dst];
    }
};
