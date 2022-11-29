//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include <bits/stdc++.h> 
//recursively traverse for the base of pick and not pick and return the 'or' of both. 
int solve(int i,int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true; //combination sum is a match
    }
    if(i==0){
        return arr[i]==target;//case where till then its not a match and first element is equal to target
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    bool notTake = solve(i-1,target,arr,dp); //we have an option of taking or not taking it
    bool take = false;
    if(target>=arr[i]){ //we can take only if target it greater or equal to index element
        take = solve(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take || notTake; //since there is no as such condition. we use 'or' logic to get any result
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}



//tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
   for(int i=0;i<n;i++) dp[i][0]= true;
    dp[0][arr[0]] = true; //case when target== arr[0] on 0th index
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
             bool notTake = dp[i-1][target]; //we have an option of taking or not taking it
    bool take = false;
    if(target>=arr[i]){ //we can take only if target it greater or equal to index element
        take = dp[i-1][target-arr[i]];
    }
     dp[i][target]=take || notTake;
        }
    }
    return dp[n-1][k];
}
