//we use cycle detection strategy for undirected graph to solve this. apply dfs on nodes and maintain a check
//if the node is safe
//TC - same as DFS
class Solution {
    
  private:
  bool dfs(int node,vector<int> adj[], int vis[],int pathVis[],int check[]){
      vis[node] = 1;
      pathVis[node] = 1;
      check[node] = 0; //indicator for safe nodes
      
      //traverse for adjacent nodes
      for(auto it: adj[node]){
          //if not visited .apply dfs
          if(!vis[it]){
              if(dfs(it,adj,vis,pathVis,check)){
                  check[node] = 0;
                  return true;
              }
          }
          //when node is already visited but must check if its in the same path
          if(pathVis[it]){
              check[node] = 0;
              return true;
          }
      }
      
      pathVis[node] = 0;  //backtrack since the current path check is done
      check[node] = 1;
      return false;
  }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
