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
