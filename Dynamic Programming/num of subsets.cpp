//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//recursively find all the combinations with pick and not pick case and return the sum of both
#include <bits/stdc++.h> 
//T.C->O(n*sum) S.C->O(n*sum)+O(n)
  int solve(vector<int>& nums, int target,int i,vector<vector<int>> &dp){
        if(target==0){ //target match found
            return 1;
        }
        if(i==0){ // if we are on the last index then that num is the deciding factor
            return target==nums[i];
        }
      if(dp[i][target]!=-1){
          return dp[i][target];
      }
        int notPick = solve(nums,target,i-1,dp); //we have an aoption of picking and not picking
        int pick = 0;
        if(target>=nums[i]){ //before picking check if its within boundary
            pick = solve(nums,target-nums[i],i-1,dp);
        }
        return dp[i][target]=pick+notPick; //since we need total num of subsets add both cases
  }
int findWays(vector<int> &num, int tar)
{
   int n = num.size(); 
   int count=0;
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return solve(num,tar,n-1,dp);
}
