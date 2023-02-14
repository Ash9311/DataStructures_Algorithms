//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance         
// User function Template for C++
//create adj list. initialize dist and src. push src to the queue and apply bfs on the queue. track the shortest distance
//TC same as BFS O(V+2E)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]); //its undirected graph
            adj[it[1]].push_back(it[0]);
        }
        
        int dist[N];
        for(int i=0;i<N;i++){
            dist[i] = 1e9; //initialize dist as infinite first
        }
        dist[src] = 0; //initialize source
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour: adj[node]){
                if(dist[node] +1<dist[neighbour]){
                    dist[neighbour] = dist[node]+1;
                    q.push(neighbour);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i]!=1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};
---------------------------------

//https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<unordered_map>
#include<list>
//T.C -> O(N+E)  S.C -> O(N+E)
//create adj list. create visited,parent vector. push source into queue and update parent, visited
//then perform bfs on it. once bfs is done and u have parent of all node. backtrack from destination
//to source via the parent reference
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    parent[s] = -1;
    queue<int> q;
    q.push(s);  //push source node into the queue
    visited[s] = true; //mark source visited as true
    
    while(!q.empty()){
        int front = q.front(); //take out front node pop and mark as visited 
        q.pop();
        visited[front] = true;
        
        for(auto neighbour: adj[front]){ //explore neighbours of each popped node
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
    
    //prepare shortest path
    vector<int> ans;
    int currNode = t; //from destination we are finding its parent by backtracking
    ans.push_back(t);
    
    while(currNode != s){ //backtrack till u get to source via parent node
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end()); //since we had backtracked from destination
    return ans;
}









---------------------------------------------
class Solution {
public:
   void BFS(vector<int> adj[],int N,int src){
       int dist[N];
       for(int i=0;i<N;i++){
           dist[i]=INT_MAX;
       }
       queue<int> q;
       dist[src]=0;
       q.push(src);
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           for(auto it:adj[node]){
               if(dist[node]+1 <dist[it] ){
                   dist[it]=dist[node+1];
                   q.push(it);
               }
           }
       }
   }
};
