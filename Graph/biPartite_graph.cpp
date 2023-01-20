
//https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
//do bfs on first node. give any color initially lets say '1' and push it to the queue. note it and pop
//check for its neighbours. if neighbour is not colored then color it with opposite of current
// -1 is uncolored, 1 & 0 are the colors that v have
//basically if the cycle in a graph is odd then its not bi-partite
//tc as same as BFS
class Solution {
    
private:

bool checkBipartiteBFS(int i,vector<int> &color,vector<int>adj[]){
    queue<int> q;
    q.push(i);
    color[i] = 1;
   
    while(!q.empty()){ //process queue elements
        int currNode = q.front();
        q.pop();
        
     for(auto it: adj[currNode]){ //process neighbours
        if(color[it]==color[currNode]){ //if neighbour's color is already same then its not bipartite
            return false;
        }
        if(color[it]==-1){ //if not color then color it with opposite
            color[it] = 1-color[currNode];
            q.push(it);
        }
    }
    }
    
    return true;
}
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	  
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!checkBipartiteBFS(i,color,adj)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};



//https://leetcode.com/problems/is-graph-bipartite/submissions/

//BFS
class Solution {
public:
    
    bool checkBipartite(int src,vector<int> &color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==color[node]){
                    return false;
                }
                else if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkBipartite(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};






//DFS
class Solution {
public:
    
    bool checkBipartiteDFS(int node,vector<int> &color,vector<vector<int>>& graph){
      if(color[node]==-1){
          color[node]=1;
      }
        for(auto it:graph[node]){
            if(color[it]==color[node]){
                return false;
            }
            else if(color[it]==-1){
                color[it]=1-color[node];
                if(!checkBipartiteDFS(it,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkBipartiteDFS(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};







