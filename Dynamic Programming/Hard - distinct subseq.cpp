//recursively explore all possibilities keeping the index same even if its a match chase to find all occurence
class Solution {
public:
//TC->O(n*m)  SC->O(n*m)+O(n+m)[recursion aux stack]
    int solve(int i,int j,string s,string t, vector<vector<int>> &dp){
        if(j==0){  //allstrings of 't' is processed so we return 1
            return 1;
        }
        if(i==0){ //all strings of 's' is exhausted but we have pending strings in 't'
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i-1]==t[j-1]){ //since strings are 0 based
            return solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);   //second recurrence stays in same index(in 'j') even if its a match to explore other possibilities
        }
        return dp[i][j]=solve(i-1,j,s,t,dp); //since we didnt find a match. move 's' index 
    }

    //tabulation
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
       // return solve(n,m,s,t,dp); //1 based indexing    ,recursion method
       for(int i=0;i<=n;i++){ //base case.
           dp[i][0]=1; //for any value of j mark all i as 1
       }
        for(int j=1;j<=m;j++){ //j starting from 1 bcz its marked as 0 in above condition
           dp[0][j]=0; //mark all value of j as 1 if i is 0
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s[i-1]==t[j-1]){
                   dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
               }
               else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return int(dp[n][m]);
    }
};
