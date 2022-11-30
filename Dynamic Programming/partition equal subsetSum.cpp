//since we have to divide array into exactly 2 parts. if array is having odd num of elements then its not possible. so our target sum is
//sumofAllelements/2 if we find this then the reamainig elements in array will sum to other half.

class Solution {
public:
    //function taken from 'subset sum equal to K' question
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
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
       
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
         if(sum%2!=0){ //not possible if sum is odd
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
        
    }
};
