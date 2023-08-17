//https://leetcode.com/problems/palindrome-partitioning/solutions/3829042/detailed-explaination-python-solution-beats-100-not-clickbait/
//        aab
//       /             |              \
//      a              aa              aab
//     / \             |     
//    a   ab           b         
//    |
//    b
class Solution {
public:
vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> ds;
        solve(s,n,ds,0);
        return res;
    }

    void solve(string s,int n,vector<string> &ds,int ind){
        if(ind==n){
            res.push_back(ds);
            return;
        }
       
       for(int i=ind;i<n;i++){
           if(isPalindrome(s,ind,i)){ //push to ds only if its a palindrome
               ds.push_back(s.substr(ind,i+1-ind));
               
               solve(s,n,ds,i+1);
               ds.pop_back();
           }
       }
        
    }

    bool isPalindrome(string str,int l,int r){
      
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
};
