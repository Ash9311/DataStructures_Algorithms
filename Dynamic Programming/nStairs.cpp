//https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//recursive iterate thorugh all possible combination and take a sum of it to find all the ways. and memoize teh values to avoid repeating
#include <bits/stdc++.h> 

int solve(int nStairs,vector<int> &dp){
    if(nStairs==0){ //if ur standing on the target stair then return 1
       return 1;
   }
    if(nStairs==1){ //since there is only 1 way
        return 1;
    }
    if(dp[nStairs]!=-1){ //check if we already have the result stored
        return dp[nStairs];
    }
    return dp[nStairs] = (solve(nStairs-1,dp)+solve(nStairs-2,dp))%1000000007;  //memoize and return
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1,-1);
    return solve(nStairs,dp);
   
}
