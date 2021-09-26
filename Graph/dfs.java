class Solution {
  public:
  
  void dfs(vector<int> adj[],int V,vector<bool> &visited,int i,vector<int> &arr){
      visited[i]=true;
      arr.push_back(i);
      for(int node: adj[i]){
          if(!visited[node]){
              dfs(adj,V,visited,node,arr);
          }
      }
  }
  
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> arr;
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,V,visited,i,arr);
            }
        }
        return arr;
    }
};
