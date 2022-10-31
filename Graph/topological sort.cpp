//https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<list>

//create an adj list. create a visited boolean vector. and perform topoSort on each of the nodes store the result
//in stack while going back and then store the reversed stack in the ans vector.

void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &st,unordered_map<int, list<int>> &adj){
    visited[node] = true;
    for(auto neighbour: adj[node]){ //dfs on neighbouring nodes
        if(!visited[neighbour]){
            topoSort(neighbour,visited,st,adj);
        }
    }
    st.push(node); //track it
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //call dfs topological sort for all components
    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,st,adj);
        }
    }
    
    vector<int> ans;
    while(!st.empty()){ //reverse the stack to get the desired ans
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
