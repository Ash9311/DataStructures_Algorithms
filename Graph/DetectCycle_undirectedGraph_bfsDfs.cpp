//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
  
  bool checkForCycle(int V,vector<int> adj[],vector<int> vis,int i){
      queue<pair<int,int>> q;
      vis[i]=true;
      q.push({i,-1});
      
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          
          q.pop();
          
          for(auto it:adj[node]){
              if(!vis[it]){
                  vis[it]=true;
                  q.push({it,node});
              }
              else if(parent!=it){
                  return true;
              }
          }
      }
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkForCycle(V,adj,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};









//DFS
class Solution {
  public:
  
  
  bool isDetectCycle(int node,int parent,vector<int> adj[],vector<int> &vis){
      vis[node]=1;
      for(auto it:adj[node]){
          if(vis[it]==0){
              if(isDetectCycle(it,node,adj,vis)) return true;
          }
          else if(it!=parent){
              return true;
          }
      }
      return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
         vector<int> vis(V+1,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(isDetectCycle(i,-1,adj,vis)){
                return true;
            }
        }
        }
        return false;
    }
};

-----------------------------------------------------
  
  // style 2
  //https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
  
 #include<unordered_map>
#include<queue>
#include<list>
//create adjacency list, visited vector. iterate through each nodes and call isCyclicBFS if not visited.

//keep track of parent node. first mark the current node as visited and push it to the queue process each node from the queue check condition for their
//neighbouring nodes.
bool isCyclicBFS(int src,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    unordered_map<int,int> parent; //keep track of parent node
    parent[src] = -1;
    vis[src] = 1;
    queue<int> q;
    q.push(src); //push src to queue
    while(!q.empty()){ //process each nodes from the queue
        int front = q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(vis[neighbour] && neighbour!=parent[front]){ //if any node is visited and neighbour isnt the parent then there is a cycle
                return true;
            }
            else if(!vis[neighbour]){ //if not a visited node then move forward by pushing it to queue and enter its parent and visited true
                q.push(neighbour);
                vis[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}
//mark node as visited first. and then process the neighbours
bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj){
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(isCyclicDFS(it,node,vis,adj)){ //recursively call its neighbours. if any 1 if it retruns true then its cyclic
                return true;
            }
        }
        else if(it!=parent){ //its cyclic if visited and not a parent
            return true;
        }
        
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int,bool> vis;
    //to handle disconnected components
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bool ans = isCyclicDFS(i,-1,vis,adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}

  
  
