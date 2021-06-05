#include <bits/stdc++.h>
using namespace std;
class ParentheseBalance {
    
public:
    
    bool isValid(string s) {
        stack<int> st;
        int n = s.size();
        bool ans = true;
        for(int i =0;i<n;i++){
            if(s[i]=='[' or s[i]=='{' or s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==']'){
                if(!st.empty() and st.top()=='['){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
             else if(s[i]=='}'){
                if(!st.empty() and st.top()=='{'){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
             else if(s[i]==')'){
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
            }
           
        }
         if(!st.empty()){
                return false;
            }
    return ans;
    }

    
};

int main(){
        ParentheseBalance obj;
        bool ans = obj.isValid("{}");
        std::cout << ans << std::endl;
<<<<<<< HEAD
    }
=======
    }
>>>>>>> origin/IP
