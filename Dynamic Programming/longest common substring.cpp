//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//since this is a substring and not a subsequence. call the recursive function in a nested for loop to try out all the combinations.
class Solution{
    
    public:
    int ans=0;
     int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        if(s1[i]==s2[j]){
            maxi= 1+solve(i-1,j-1,s1,s2,dp); //add +1 if its a match and track the max
            ans = max(ans,maxi);
        }
        return dp[i][j]=maxi; //memoize
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,S1,S2,dp);
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } D
