//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

//COMPUTE toposort. if toposort contains all the vertices then we can say that there are not cycle and hence
//return true else false
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
      int indegree[N] = {0};
      for(int i=0;i<N;i++){
          for(auto it: adj[i]){ //take out indegrees
              indegree[it]++;
          }
      }
      
      queue<int> q;
      for(int i=0;i<N;i++){
          if(indegree[i]==0){   //push those nodes into the queue whose indegree is 0
              q.push(i);
          }
      }
      
      vector<int> topo;
      
      //O(V+E)
      while(!q.empty()){ //process nodes with indegree 0
          int node = q.front();
          q.pop();
          topo.push_back(node);
          
          for(auto it: adj[node]){
              indegree[it]--;  //subtract the indegree of curr node from its neighbours
              if(indegree[it]==0){
                  q.push(it);
              }
          }
      }
     if(topo.size()==N){
         return true;
     }
     return false;
	}
};
