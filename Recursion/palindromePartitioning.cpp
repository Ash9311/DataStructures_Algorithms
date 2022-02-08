//https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(s,0,res,path);
        return res;
    }
    
    void solve(string s,int index,vector<vector<string>> &res,vector<string> &path){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1,res,path);
                path.pop_back();
                
            }
        }
    }
    
    bool isPalindrome(string s,int start,int end){
        while(start<end){
        if(s[start++]!=s[end--]){
            return false;
        }
        }
        return true;
    }
};
