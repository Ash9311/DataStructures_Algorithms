//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//create adj list. iterate through each node recursively with dfs. maitain a visited and dfsVisited map
//cycle is said to be detected in directed graph when visited and dfsVisited is true
//TC - O(V+E),  SC - O(2N)
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
    dfsVisited[node] = false; //backtrack dfsVisited, through DFS visited we get to know the current path. once done we backtrack it
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



------------------------------------------------------------
    //using kahn's algo
    //T.C - O(N+E)   S.C - O(N+E)
//create adj list. maintain a indegree vector. if indegree of any node is zero then push it to the queue
//perform BFS on the queue, update count and the indegree as you pop nodes on queue. check if count is equal to n
   
#include<unordered_map>
#include<list>
#include<queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first -1; //-1 since nodes are starting from 1
        int v = edges[i].second -1;
        adj[u].push_back(v);
    }
    
    //find all indegrees
    vector<int> indegrees(n);
    for(auto it: adj){
        for(auto j: it.second){
            indegrees[j]++;
        }
    }
    
    //push 0 indegree nodes
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    
    //do BFS
    int count=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //update count
        count++;
        
        //update neighbour indegree
        for(auto neighbour:adj[front]){
            indegrees[neighbour]--;
            if(indegrees[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
  if(count==n){ //if graph is topological then count would be same as num of nodes
      return false;
  }
    return true;
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
