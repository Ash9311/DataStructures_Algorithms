//https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//recursive traverse through all the indexes but this problem is quiet different here since we can pick the same coin multiple times
//we can stay on the same index after we pick .we wont be stuck there since target reduces as we pick . so recursion will go too deeply
//it finds all the combinations

//T.C -> O(n*w) S.C->O(n*w) + O(w) (recursion aux space is huge coz v stay on same index. )
//witout memoization - >T.C -> much greater than(O(2^n)) S.C->O(w)
#include <bits/stdc++.h> 

int solve(int i,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    if(i==0){
        if(weight[i]<=w){ //if on the last index. just take how much u can
            int temp = w/weight[i];
            return (w/weight[i])*profit[i]; //no. of items tht can be taken times its value
        }
        return 0;
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    int notPick = 0+ solve(i-1,w,profit,weight,dp);
    int pick = 0;
    if(weight[i]<=w){
        pick = profit[i]+solve(i,w-weight[i],profit,weight,dp); //not changing the index since there is infinite supply
    }
    return dp[i][w]=max(pick,notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}
