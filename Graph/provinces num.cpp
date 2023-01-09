//https://leetcode.com/problems/number-of-provinces/description/
//create adjacency list. traverse through all vertices and call dfs on them also track visited. from visited we get to know the count of
//unconnected cities
//SC - > O(N) + O(N)   TC->O(N) + O(V+2E)
class Solution {

private:
 void dfs(int node,vector<int> adjL[],vector<int> &vis){
     vis[node] = 1;
     for(auto it: adjL[node]){
         if(!vis[it]){
             dfs(it,adjL,vis);
         }
     }
 }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjL[V];
        for(int i=0;i<V;i++){ //create adjacency list
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
      
        vector<int> vis(V,0);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;  //track count, connected nodes will be marked as visisted and we get count of non connected graphs
                dfs(i,adjL,vis);
            }
        }
        return count;
    }
};
