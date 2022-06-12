//https://leetcode.com/problems/valid-parentheses/submissions/

//iterate through each and every char and check for opening and closing braces, if opening push it to the stack else check if it symmetric one
//is at the stack.top()
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n = s.length();
        bool result = true;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
              else if(s[i]=='}'){
                if(!st.empty() and st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
              else if(s[i]==']'){
                if(!st.empty() and st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
