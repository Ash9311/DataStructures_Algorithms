class Solution {
  public:
  
  bool dfs(vector<int> adj[],int curr,vector<bool> &visit,vector<bool> &stack){
      visit[curr]=true;
      stack[curr]=true;
      for(auto it: adj[curr]){
          if(!visit[it] and dfs(adj,it,visit,stack)){
              return true;
          }
          else if(stack[it]){
              return true;
          }
      }
     stack[curr]=false;
     return false;
  }
  
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visit(V,false);
        vector<bool> stack(V,false);
        
        for(int i=0;i<V;i++){
            if(!visit[i] && dfs(adj,i,visit,stack)){
                return true;
            }
        }
        return false;
        
    }
};
