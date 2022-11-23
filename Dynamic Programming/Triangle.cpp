//https://leetcode.com/problems/triangle/

class Solution {
    //recursively explore down and diagonal direction and return the min.. in case of last row return the same u go into
public:
    //T.C -> O(n*n)  S.C-> O(n*n) + recursion stack
    int solve(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp){
            if(row==n-1){
                return triangle[row][col];
            }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
            int down = triangle[row][col] + solve(row+1,col,n,triangle,dp); //since we can move down,diagonally only
        int diagonal = triangle[row][col] + solve(row+1,col+1,n,triangle,dp);
        return dp[row][col]=min(down,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,n,triangle,dp);
    }
};
