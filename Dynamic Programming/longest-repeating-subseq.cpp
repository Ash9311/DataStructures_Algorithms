//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//The code recursively explores all possible character matches between the two strings, 
//considering the possibility of including or excluding each character.
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    string txt(str.begin(),str.end()); //copied string
		    vector<vector<int>> dp(n,vector<int>(n,-1));
		    return solve(n-1,n-1,str,txt,dp);
		}
		
		int solve(int i,int j,string &str,string &txt,vector<vector<int>> &dp){
		    if(i<0 || j<0) return 0;
		    if(dp[i][j]!=-1) return dp[i][j];
		    if(str[i]==txt[j] && i!=j){ //there is a common character that can be a part of the repeating subsequence. 
		        return 1+solve(i-1,j-1,str,txt,dp);
		    }
		    return dp[i][j]=max(solve(i-1,j,str,txt,dp),solve(i,j-1,str,txt,dp)); // returns the maximum length from these two possibilities.
		}

};
