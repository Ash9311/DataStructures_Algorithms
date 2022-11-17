//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//maitain a dp vector and recursively implement pick and nopick scenario, storing the result in dp vector.
//T.C -> O(N)   S.C -> O(N) + O(N) 
static int f(int index,vector<int> &nums,vector<int> &dp){
    if(index==0){ //base condition
        return nums[index];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){ //return if memoized value is present
        return dp[index];
    }
    int pick = nums[index] + f(index-2,nums,dp);  //since v r picking and we cannot pick adjacent next so index-2
    int notpick = 0 + f(index-1,nums,dp); //dont pick and go to adjacent index
    
    return dp[index]=max(pick,notpick); //memoize for future reference
}

int maximumNonAdjacentSum(vector<int> &nums){
 	int n =nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}


//tabulation        T.C -> O(N)   S.C -> O(N)
int maximumNonAdjacentSum(vector<int> &nums){
 	int n =nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    int neg = 0;
    for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>1){ //edge case
            pick +=dp[i-2];
        }
        int nopick = 0 + dp[i-1];
        dp[i] = max(pick,nopick);
    }
    return dp[n-1];
}


//space optimization
int maximumNonAdjacentSum(vector<int> &nums){
 	int n =nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>1){ //edge case
            pick +=prev2;
        }
        int nopick = 0 + prev;
        int curr = max(pick,nopick);
        prev2 = prev;
        prev = curr;   
    }
    return prev;
}
