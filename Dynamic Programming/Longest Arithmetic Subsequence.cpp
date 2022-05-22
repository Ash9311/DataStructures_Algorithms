class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int res;
        unordered_map<int,unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j]-nums[i];
                dp[diff][j] = dp[diff].count(i) ? dp[diff][i]+1 : 2;
                res = max(res,dp[diff][j]);
            }
        }
        return res;
    }
  
 //avoids TLE   
//      int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         int result = 0;
//         int res;
//          vector<vector<int>> dp(n,vector<int>(2000,0));
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int diff = nums[j]-nums[i] + 1000;
//                 dp[j][diff] = max(2,dp[i][diff]+1);
//                 res = max(res,dp[j][diff]);
//             }
//         }
//         return res;
//     }
};
