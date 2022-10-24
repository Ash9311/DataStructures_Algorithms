//maintain a visited function to skip processed nodes. and a queue to keep track of adjacent nodes of each nodes. add non visited nodes to the queue.
//pop each non-visited node from queue and add it to the ans
//traverse its adj nodes and mark as visited
class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean visited[] = new boolean[V];
        ArrayList<Integer> arr = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        visited[0]=true;
        while(!(q.isEmpty())){
            int node = q.poll();
            arr.add(node);
            
            for(int it : adj.get(node)){
                if(visited[it]==false){
                    visited[it]=true;
                    q.add(it);
                }
            }
        }
        return arr;
        
        
        
    }
}


//CPP

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> result;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!(q.empty())){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        return result;
    }
};
