//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
class Solution {
public:
    int minAddToMakeValid(string s) {
            stack<int> st;
            int count = 0;
            int n =s.size();
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    st.push(i); //insert only openings
                }
                else if(s[i]==')'){
                    if(!st.empty()){
                        st.pop(); //pop out balanced ones
                    }
                    else{
                        count++; //case where '(' not there. but count it as it needs to b balanced
                    }
                }
            }
            count+=st.size(); //remaining ones which needs to be balanced
            return count;
    }
};
