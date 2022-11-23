//https://leetcode.com/problems/minimum-path-sum/
//T.C->O(n*m) S.C->O(n*m) + O(path length i.e m-1 + n-1)

//recurisvely explore all indexes. maintain a DP vector, base condition and return the minimum of up,left

class Solution {
public:
    
    int solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(row==0 && col==0){
            return grid[row][col]; //include the grid weight while returning
        }
        if(row<0 || col<0){
            return INT_MAX-15; //since this path cannot be considered return a max value 
        }
        
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int up = grid[row][col] + solve(row-1,col,grid,dp); //include the current grid weight in the sum and move ahead
        int left = grid[row][col] + solve(row,col-1,grid,dp);
        return dp[row][col]=min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int sum = 0;
        return solve(n-1,m-1,grid,dp);
    }
};

//tabulation
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
       for(int row=0;row<n;row++){ //iterate for all indexes
           for(int col=0;col<m;col++){
               if(row==0 && col==0){
                   dp[row][col] = grid[row][col]; //store recurrence
               }
               else{
               int up = grid[row][col];
               if(row>0){
                   up += dp[row-1][col];
               }
               else{
                   up += 1e9;
               }
               int left = grid[row][col];
               if(col>0){
                   left+=dp[row][col-1];
               }
               else{
                   left += 1e9;
               }
               dp[row][col] = min(up,left);
               }
           }
       }
        return dp[n-1][m-1];
    }

//space optimization
 int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0);
        vector<vector<int>> dp(n,vector<int>(m,0));
       for(int row=0;row<n;row++){
           vector<int> curr(m,0);
           for(int col=0;col<m;col++){
               if(row==0 && col==0){
                   curr[col] = grid[row][col];
               }
               else{
               int up = grid[row][col];
               if(row>0){
                   up += prev[col];
               }
               else{
                   up += 1e9;
               }
               int left = grid[row][col];
               if(col>0){
                   left+=curr[col-1];
               }
               else{
                   left += 1e9;
               }
               curr[col]= min(up,left);
               }
           }
           prev = curr;
       }
        return prev[m-1];
    }
