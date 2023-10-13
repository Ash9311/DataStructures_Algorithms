//https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        int ans = 0;
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }

    int solve(string s,int i,vector<int> &dp){
        if(i==s.size()) return 1; //empty string has 1 way to decode
        if(s[i]=='0') return 0;
        int ways = 0;

        if(dp[i]!=-1) return dp[i];

        //single digit 
        ways+=solve(s,i+1,dp);
    
        //two digit check if possible
        if(i+1<s.size() && s[i]!='0' && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
           
            ways +=solve(s,i+2,dp);
            
        }
        return dp[i]=ways;

    }
};
