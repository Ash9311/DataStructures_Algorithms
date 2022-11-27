//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h> 
//this involves 3D DP. i.e row will increase by 1. and there are 2 people(starting at 0 and c-1 initially). so each have
//3 columns to visit. that turns out to be 9 combinations. whereas the row that they will be going to is always common. represented by
//row,col1,col2
int solve(int row,int col1,int col2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    if(col1<0 || col2<0 || col1>grid[0].size()-1 ||col2>grid[0].size()-1 ){ //boundary condition- return large -ve value so it goes out of our search
        return -1e8;
    }
    if(row==grid.size()-1){
        if(col1==col2) return grid[row][col1]; //since both alice and bob r on same cell. count only 1
        else return grid[row][col1]+grid[row][col2];
    }
    
    if(dp[row][col1][col2]!=-1){ //return the memoized value if its already computed
        return dp[row][col1][col2];
    }
    
    //explore all paths of alice and bob simultaneously
    int maxi = -1e8;
    for(int dcol1=-1; dcol1<=+1; dcol1++){ //dcol is the delta change in col to compute those 9 combinations
        for(int dcol2=-1; dcol2<=+1;dcol2++){
            int value = 0;
            if(col1==col2) value = grid[row][col1]; //same cell ,count only 1
            else value = grid[row][col1] + grid[row][col2];
            value += solve(row+1,col1+dcol1,col2+dcol2,grid,dp); //recursivel explore other possibilities
            maxi = max(maxi,value); //track the max
        }
    }
    return dp[row][col1][col2]=maxi; //memoize in 3d DP
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1))); //declare 3D DP
    return solve(0,0,c-1,grid,dp);
}
