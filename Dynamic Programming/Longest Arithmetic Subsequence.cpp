
The main idea is to maintain a map of differences seen at each index.

We iteratively build the map for a new index i, by considering all elements to the left one-by-one.
For each pair of indices (i,j) and difference d = A[i]-A[j] considered, we check if there was an existing chain at the index j with difference d already.

If yes, we can then extend the existing chain length by 1.
Else, if not, then we can start a new chain of length 2 with this new difference d and (A[j], A[i]) as its elements.
At the end, we can then return the maximum chain length that we have seen so far.

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
