

//apply DFS starting from 0. mark as visited check for neighbours ,push it to the stack after cheking for neighbours.
//once all are traversed. return all the elements populated in stack
//TC - O(V+E) same as dfs for directed graphs
//topological sorting is a method of sorting where if you pickup an element frm a stack. u get to know that DFS
//has been done for that
class Solution
{
    
    private:
    void DFS(int node,vector<int> adj[],int vis[],stack<int> &st){
        vis[node] = 1;
        
        for(auto it: adj[node]){ //check for neighbours
            if(!vis[it]){
                DFS(it,adj,vis,st);
            }
            
        }
        st.push(node); //push it to the stack after cheking for its neighbours
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            DFS(i,adj,vis,st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};








----------------------------



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


-----------------------------------------------------------------
//using Kahn's algo

#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<list>
//T.C - O(N+E)   S.C - O(N+E)
//create adj list. maintain a indegree vector. if indegree of any node is zero then push it to the queue
//perform BFS on the queue, store ans and update the indegree as you pop nodes on queue.
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //find all indegrees
    vector<int> indegrees(v);
    for(auto it: adj){
        for(auto j: it.second){
            indegrees[j]++;
        }
    }
    
    //push 0 indegree nodes
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    
    //do BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //store ans;
        ans.push_back(front);
        
        //update neighbour indegree
        for(auto neighbour:adj[front]){
            indegrees[neighbour]--;
            if(indegrees[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
 return ans;
}
