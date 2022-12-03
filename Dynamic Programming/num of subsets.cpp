//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//recursively find all the combinations with pick and not pick case and return the sum of both
#include <bits/stdc++.h> 
//T.C->O(n*sum) S.C->O(n*sum)+O(n)
  int solve(vector<int>& nums, int target,int i,vector<vector<int>> &dp){
       if(i==0){
           if(target==0 && nums[0]==0) return 2; //since there are 2 possibilities considering or not considering 0
           if(target==0 || target==nums[0]) return 1;
           return 0;
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


//tabulation
int findWays(vector<int> &num, int tar)
{
   int n = num.size(); 
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(num[0] <=tar) dp[0][num[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notPick = dp[ind-1][sum];
            int pick = 0;
            if(num[ind]<=sum) pick = dp[ind-1][sum-num[ind]];
            dp[ind][sum] = notPick + pick;
        }
    }
    return dp[n-1][tar];
}


//space optimization
int findWays(vector<int> &num, int tar)
{
   int n = num.size(); 
    vector<int> prev(tar+1,0), curr(tar+1,0);
    prev[0] = curr[0] = 1;
    if(num[0] <=tar) prev[num[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(num[ind]<=sum) pick = prev[sum-num[ind]];
            curr[sum] = notPick + pick;
        }
        prev = curr;
    }
    return prev[tar];
}
