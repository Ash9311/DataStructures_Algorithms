//https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
//maintain a visited vector and path string.Implement safe function to check for boundaries. explore all combination routes if it is safe

bool isSafe(int i,int j,vector<vector<bool>> &visited,vector < vector < int >> & arr,int n){
    if((i<n && i>=0) && (j<n && j>=0) && !visited[i][j] && arr[i][j]==1){ //check boundaries and obstacles
        return true;
    }
    return false;
}

void solve(int i,int j,vector < vector < int >> & arr, int n,vector<string> &ans,vector<vector<bool>> &visited,string path){
    if(i==n-1 and j==n-1){
        ans.push_back(path);
        return;
    }
     visited[i][j]=1; //mark as visited
    //down
    if(isSafe(i+1,j,visited,arr,n)){
        solve(i+1,j,arr,n,ans,visited,path+'D');
    }
    
     //left
    if(isSafe(i,j-1,visited,arr,n)){
         solve(i,j-1,arr,n,ans,visited,path+'L');
    }
    
     //right
    if(isSafe(i,j+1,visited,arr,n)){
        solve(i,j+1,arr,n,ans,visited,path+'R');
    }
    
    //up
    if(isSafe(i-1,j,visited,arr,n)){
         solve(i-1,j,arr,n,ans,visited,path+'U');
    }
   
   
     visited[i][j]=0; //back track
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0)); //to track visited
    string path = ""; //to track path taken
    if(arr[0][0]==0){ //base case
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}
