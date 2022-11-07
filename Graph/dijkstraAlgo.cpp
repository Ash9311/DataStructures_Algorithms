//https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
//find adj list of pairs since weight is involved and it is undirected. initialize dist vector, maitain a
//set of pair of distance from source and node. iterate through the set and process
//T.C-> O(ElogV)  S.C -> O(N+E)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj; //list has pair of neighbour node and weight
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); //since its undirected graph
    }
    
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){ //initialize all dist vertices as infinity
        dist[i] = INT_MAX;
    }
    set<pair<int,int>> set; //pair of distance from source and node
    dist[source] = 0; //since dist from source to source is 0
    set.insert(make_pair(0,0));
    
    while(!set.empty()){
        //fetch the top record
        auto top = *(set.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;
        
        //remove top record
        set.erase(set.begin());
        
        //traverse on neighbours
        for(auto neighbour: adj[topNode]){
            if(nodeDistance+neighbour.second < dist[neighbour.first]){
                auto record = set.find(make_pair(dist[neighbour.first],neighbour.first)); //if record is already there then delete it
                if(record!=set.end()){
                    set.erase(record);
                }
                
                //distance update
                dist[neighbour.first] = nodeDistance+neighbour.second;
                //push record into set
                set.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}


-----------------------
//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distTo(V,INT_MAX);
        distTo[S]=0;
        pq.push(make_pair(0,S));
        while(!pq.empty()){
            int dist = pq.top().first;
            int prev = pq.top().second;
            
            pq.pop();
            vector<pair<int,int>>::iterator it;
            for(auto it: adj[prev]){
                int next = it[0];
                int nextDist=it[1];
                if(dist+nextDist < distTo[next]){
                    distTo[next] = dist + nextDist;
                    pq.push(make_pair(distTo[next],next));
                }
            }
        }
        
        return distTo;
    }
};

