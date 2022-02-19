//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


static int f(int index,vector<int> &nums,vector<int> &dp){
    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int pick = nums[index] + f(index-2,nums,dp);
    int notpick = 0 + f(index-1,nums,dp);
    
    return dp[index]=max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
 	int n =nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}
