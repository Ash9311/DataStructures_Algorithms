//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h> 
//we are writing for dest to src. so that top down approach becomes easier.
//declare a dp vector to memoize and start fromn m-1,n-1 . write base condition,boundary condition
//recursively explore all possibilities on each index and store and return the sum.
int f(int i,int j,vector<vector<int>> &dp){
    if(i==0 and j==0){ //top down appraoch base condition
        return 1;
    }
    if(i<0 or j<0){ //out of boundary
        return 0;
    }
    if(dp[i][j]!=-1){ //check for overlapping sub problem
        return dp[i][j];
    }
    int up = f(i-1,j,dp); //recursively call for up,left
    int left = f(i,j-1,dp);
    return dp[i][j]=up+left; //memoize
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
	return f(m-1,n-1,dp);
}
