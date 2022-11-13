//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
#include<list>
#include<vector>
//T.C -> O(n*n)
//create adj list with weights. declare 3 data structures i.e key( which contains min distances), 
//MST(To track if node is in MST) and parent
//iterate through all the nodes. find the minimum value in key and mark as true. traverse its adj nodes
//and push required ans in the result
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //n is nodes, m is edges
    // Write your code here.
    //create adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); //since its undirected graph
    }
    
    vector<int> key(n+1); // +1 bcz index starts from 1, will contain min distance between nodes (weight)
    vector<bool> mst(n+1); //to track if a node is present in MST
    vector<int> parent(n+1); //to keep track of node's parent
    
    for(int i=0;i<=n;i++){ //initialize values
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    
    //lets start the algo
    key[1] = 0; //set source and parent value
    parent[1] = -1;
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;
        //find mini
        for(int v=1;v<=n;v++){
            if(mst[v]==false and key[v]<mini){ //condition to find mini
                u = v;
                mini = key[v];
            }
        }
        //mark min node as true
        mst[u] = true;
        
        //check adj nodes
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false and w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
        vector<pair<pair<int, int>, int>> result;
        for(int i=2;i<=n;i++){
            result.push_back({{parent[i],i},key[i]}); //pair of u and v..,weight
        }
        return result;
}
