//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//create adj list. iterate through each node recursively with dfs. maitain a visited and dfsVisited map
//cycle is said to be detected in directed graph when visited and dfsVisited is true
#include<unordered_map>
#include<list>
bool checkCycleDFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited,adj);
            if(cycleDetected){ //we get recursive call result here
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false; //backtrack dfsVisited
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    
    //create adj list
    unordered_map<int,list<int>> adj;
    for(auto it: edges){
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v); 
    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited; //incase of directed graph v need to keep track of dfs call to check for a cycle else v will find a closed loop but it cannot b considered as a cycle
    //call dfs for all components
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound){
                return true;
            }
        }
    }
    return false;
}







----------------------------------------------------------

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
