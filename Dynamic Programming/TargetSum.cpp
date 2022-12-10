//https://leetcode.com/problems/target-sum/description/

//question similar to partition with given difference. its just represented in different way
//take the sum of all elements and make an equation to find one of the subset. 
//recursively find all ways to get that target
class Solution {
public:

int mod=(int)(1e9 + 7);
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
        return dp[i][target]=(pick+notPick)%mod; //since we need total num of subsets add both cases
  }
int findWays(vector<int> &num, int tar)
{
   int n = num.size(); 
   int count=0;
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return solve(num,tar,n-1,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum=0;
    for(auto it:arr){
        totSum+=it;
    }
    //sub1 - sub2 = d
    // totSum = sub1 + sub2;  sub1 = totSum-sub2
    //totSum - sub2 - sub2 = d
    //sub2 = (totSum-d)/2    and vice-versa for sub1
    if(totSum-d <0 ||  (totSum-d)%2) return 0;  //edge cases  i.e difference greater than sum and odd sum case
    return findWays(arr,(totSum-d)/2); //one of the subset is our target
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};
