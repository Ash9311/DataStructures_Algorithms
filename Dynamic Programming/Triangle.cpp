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
    
    ----------------
    //tabulation method
        //T.C -> O(n*n)  S.C-> O(n*n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
       for(int col=0;col<n;col++){
           dp[n-1][col] = triangle[n-1][col]; //fill the last row first
       }
        for(int row=n-2;row>=0;row--){ //do it for remaining
            for(int col=row;col>=0;col--){
                int down = triangle[row][col] + dp[row+1][col];
                int diagonal = triangle[row][col] + dp[row+1][col+1];
                dp[row][col] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
    
    
     //space optimization 
    //T.C -> O(n*n)  S.C-> O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0), curr(n,0);
       for(int col=0;col<n;col++){
           front[col] = triangle[n-1][col]; //fill the last row first
       }
        for(int row=n-2;row>=0;row--){ //do it for remaining
            for(int col=row;col>=0;col--){
                int down = triangle[row][col] + front[col];
                int diagonal = triangle[row][col] + front[col+1];
                curr[col] = min(down,diagonal);
            }
            front = curr;
        }
        return front[0];
    }
    
};
