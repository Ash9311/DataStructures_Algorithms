//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

//find topo sort. then create shortest dist vector with infinite distance initially. process stack containing toposort
//to find shortest distance
//tc sam as DFS
class Solution {
  public:
  
    void topoSort(int node,vector<pair<int,int>> adj[], int vis[], stack<int> &st){
        vis[node] = 1;
        for(auto neighbour: adj[node]){
            int v = neighbour.first;
            if(!vis[v]){
            topoSort(v,adj,vis,st);
            }
        }
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //find the topo sort
        int vis[N] = {0};
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        
        //do the distance thing
        vector<int> dist(N);
        for(int i=0;i<N;i++){
            dist[i] = 1e9;
        }
        dist[0] = 0;
        //O(N+M)
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
              //  cout<<dist[node]+wt<<" "<<dist[v]<<endl;
                if(dist[node] + wt <dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for(int i=0;i<dist.size();i++){ //if any node is impossible to reach make it -1
            if(dist[i]==1000000000){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
----------------------------

#include <bits/stdc++.h>
#include<iostream>
#include<list>
using namespace std;
//T.C-> O(N+E)   S.C->O(N+E)
//first find the topological sort and insert it in a stack . using topo sort data we get the min distance from src to all nodes 
class Graph{
 public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

void dfs(int node, vector<bool> &visited,stack<int> &topo){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour.first]){
            dfs(neighbour.first,visited,topo);
        }
    }
    topo.push(node); //insert the depth node to stack. thats what topological sort is
}

void getShortestPath(int src,vector<int> &dist,stack<int> &topo){
    dist[src] = 0; //distance from src to src is zero

    while(!topo.empty()){ //process for each node that is in the stack
        int top = topo.top();
        topo.pop();

        if(dist[top]!=INT_MAX){
            for(auto i: adj[top]){
                if(dist[top]+i.second < dist[i.first]){ //if distance is lesser than prev computed then update
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
}
};

int main(){
    //construct graph
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);    
    g.printAdj();
    int n = 6;
    vector<bool> visited(n,false); //declare visited vector and stack to obtain topo order
    stack<int> st;
    //topological sort
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,st);
        }
    }

    int src = 1; //our source node
    vector<int> dist(n); // dist vector to store shortest distance
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX; //initialize it with max first
    }
    g.getShortestPath(src,dist,st);
    cout<<"answer is:"<<endl;

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";   //print it
        
    }cout<<endl;
   
    return 0;
}
