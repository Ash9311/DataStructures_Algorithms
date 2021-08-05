/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
     private LinkedList<Integer> adj[];
	    public void Graph(int v){
	        adj = new LinkedList[v];
	        for(int i = 0;i<v;i++){
	            adj[i] = new LinkedList<Integer>();
	        }
	    }
	    
	    public void addEdge(int source, int destination){
	        adj[source].add(destination);
	        adj[destination].add(source);
	    }
	    
	    public void bfs(int source, int destination){
	        boolean vis[] = new boolean[adj.length];
	        int parent[] = new int[adj.length];
	        Queue<Integer> q = new LinkedList<>();
	        q.add(source);
	        parent[source] = -1;
	        
	        while(!q.isEmpty()){
	            int cur = q.poll();
	            if(cur == destination){
	                break;
	            }
	            for(int neighbor: adj[cur]){
	                if(!vis[neighbor]){
	                    q.add(neighbor);
	                    parent[neighbor] = cur;
	                }
	            }
	        }
	        int cur = destination;
	        int distance = 0;
	        while(parent[cur]!=-1){
	            System.out.println(cur+" -> ");
	            cur = parent[cur];
	            distance++;
	        }
	    }
	    
	    private boolean dfsUtil(int source, int destination, boolean vis[]){
	        if(source == destination){
	            return true;
	        }
	        
	        for(int neighbor: adj[source]){
	            if(!vis[neighbor]){
	                vis[neighbor] = true;
	                boolean isConnected = dfsUtil(neighbor, destination,vis);
	                if(isConnected){
	                    return true;
	                }
	                
	            }
	        }
	        return false;
	    }
	    
	    public boolean dfsStack(int source,int destination){
	        boolean vis[] = new boolean[adj.length];
	        vis[source] = true;
	        Stack<Integer> = new Stack<>();
	        
	        Stack.push(source);
	        
	        while(!stack.isEmpty()){
	            int cur = stack.pop();
	            
	            if(cur==destination){
	                return true;
	            }
	            
	            for(int neighbor: adj[cur]){
	                if(!vis[neighbor]){
	                    vis[neighbor]=true;
	                    stack.push(neighbor);
	                }
	            }
	        }
	        return false;
	    }
	    
	    public boolean dfs(int source, int destination){
	        boolean vis[] = new boolean[adj.length];
	        vis[source] = true;
	        
	        return dfsUtil(source,destination,vis);
	    }
	    
	public static void main (String[] args) throws java.lang.Exception
	{
	   
	    Scanner sc=new Scanner(System.in);
	    System.out.println("Enter number of vertices and graphs");
	    int v = sc.nextInt();
	    int e = sc.nextInt();
	    Graph graph = new Graph(v);
	    System.out.println("Enter "+e+" edges");
	    for(int i=0; i<e; i++){
	        int source = sc.nextInt();
	        int destination = sc.nextInt();
	        
	        graph.addEdge(source,destination);
	    }
	    System.out.println("Enter source and destination");
	    int source = sc.nextInt();
	    int destination = sc.nextInt();
	    
	    int destination = graph bfs(source, destination);
	    System.out.println("min distance is "+distance);
	    sc.close();
	}
}
