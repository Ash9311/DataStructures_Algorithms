//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
//maintain a DP vector. explore all paths recursively starting from last row. first compute all col of last row and then
//return the max sum path
int solve(int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(col<0 || col>matrix[0].size()-1 || row<0){ //boundary conditions
        return -1e8; //-1e8 bcz INT_MIN wil got out of hand
    }
    if(row==0){
        return matrix[row][col]; //return whaterver col its in on that recursive exploration
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int up = matrix[row][col] + solve(row-1,col,matrix,dp);
    int leftDiagonal = matrix[row][col] + solve(row-1,col-1,matrix,dp);
    int rightDiagonal = matrix[row][col] + solve(row-1,col+1,matrix,dp);
    return dp[row][col]=max(up,max(leftDiagonal,rightDiagonal)); //return and memoize
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //row length
    int m = matrix[0].size(); //col length
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxi = -1e8;
    for(int col=0;col<m;col++){ //since we have an option of start point. we try all col in last row and return the max of all
        maxi = max(maxi,solve(n-1,col,matrix,dp));
    }
    return maxi;
}

//tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //row length
    int m = matrix[0].size(); //col length
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int col=0;col<m;col++){ //initialize col values for 0th row
        dp[0][col] = matrix[0][col];
    }
    for(int row=1;row<n;row++){ //compute for rest of the rows
        for(int col=0;col<m;col++){
            int up = matrix[row][col] + dp[row-1][col];
            int leftDiagonal = matrix[row][col];
            if(col-1>=0) leftDiagonal+=dp[row-1][col-1]; //boundary condition, add only if its within
            else leftDiagonal += -1e8; //else make it go out of our search
            int rightDiagonal = matrix[row][col];
            if(col+1<m) rightDiagonal+=dp[row-1][col+1];
            else rightDiagonal += -1e8;
            dp[row][col] = max(up,max(leftDiagonal,rightDiagonal)); //memoize
        }
    }
    int maxi = -1e8;
    for(int col=0;col<m;col++){ //find the max value in the last row
        maxi = max(maxi,dp[n-1][col]);
    }
    return maxi;
}


//tabulation & space optimized
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(); //row length
    int m = matrix[0].size(); //col length
    vector<int> prev(m,0), curr(m,0); //since we need only curr and prev row values. we can get rid of 2D DP vector
    for(int col=0;col<m;col++){ //initialize col values for 0th row
        prev[col] = matrix[0][col];
    }
    for(int row=1;row<n;row++){ //compute for rest of the rows
        for(int col=0;col<m;col++){
            int up = matrix[row][col] + prev[col];
            int leftDiagonal = matrix[row][col];
            if(col-1>=0) leftDiagonal+=prev[col-1]; //boundary condition, add only if its within
            else leftDiagonal += -1e8; //else make it go out of our search
            int rightDiagonal = matrix[row][col];
            if(col+1<m) rightDiagonal+=prev[col+1];
            else rightDiagonal += -1e8;
            curr[col] = max(up,max(leftDiagonal,rightDiagonal)); //memoize
        }
        prev = curr;
    }
    int maxi = -1e8;
    for(int col=0;col<m;col++){ //find the max value in the last row
        maxi = max(maxi,prev[col]);
    }
    return maxi;
}
