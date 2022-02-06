//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

bool isSafe(int node,bool graph[101][101],int col,int V,int color[]){
    for(int k=0;k<V;k++){
        if(k!=node and color[k]==col and graph[k][node]==1){
            return false;
        }
    }
    return true;
}

bool solve(int node,bool graph[101][101],int m,int V,int color[]){
    if(node==V){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isSafe(node,graph,i,V,color)){
            color[node]=i;
            if(solve(node+1,graph,m,V,color)){
                return true;
            }
            color[node]=0;
           
        }
    }
     return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    if(solve(0,graph,m,V,color)){
        return true;
    }
    return false;
}
