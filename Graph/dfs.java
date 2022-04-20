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


//cpp
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &storeDFS){
        storeDFS.push_back(node);
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,vis,adj,storeDFS);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> storeDFS;
        vector<int> vis(V+1,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,storeDFS);
            }
        }
        return storeDFS;
    }
};
