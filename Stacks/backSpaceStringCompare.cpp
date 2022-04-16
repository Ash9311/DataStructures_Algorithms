//https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<string> st1;
        stack<string> st2;
        
        for(int i=0;i<s.size();i++){
            
              if(s[i]=='#' and st1.empty()){
                 continue;
             }
            if(s[i]=='#'){
                st1.pop();
            }
            else{
                st1.push(to_string(s[i]));
            }
        }
        
         for(int i=0;i<t.size();i++){
             
             if(t[i]=='#' and st2.empty()){
                 continue;
             }
             
            if(t[i]=='#'){
                st2.pop();
            }
            else{
                st2.push(to_string(t[i]));
            }
        }
        
        if(st1.size()!=st2.size()){
            return false;
        }
        
        while(!st1.empty()){
            cout<<st1.top()<<" "<<st2.top()<<endl;
            if(st1.top()!=st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};
