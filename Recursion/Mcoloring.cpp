//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
//start from node 0 and apply all colors and recursively check for all conditions satisfying different combinations

bool isSafe(int node,int color[],bool graph[101][101],int n,int colr){
    for(int k=0;k<n;k++){ //iterate through adjacent nodes
        if(k!=node and  graph[k][node]==1 and color[k]==colr){
            return false;
        }
    }
    return true;
}

bool solve(int node,int color[],bool graph[101][101],int m,int n){
    if(node==n){  //reached the end without returning false
        return true;
    }
    for(int i=1;i<=m;i++){ //try for all colors
        if(isSafe(node,color,graph,n,i)){
            color[node]=i;
            if(solve(node+1,color,graph,m,n)){
                return true;
            }
            color[node]=0; //backtrack
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int color[n]={0};
    if(solve(0,color,graph,m,n)==true){
        return true;
    }
    return false;
}
