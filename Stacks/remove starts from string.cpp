//https://leetcode.com/problems/removing-stars-from-a-string/
//maintain a stack, pop 2 elements if you find a '*' and then push stack content into a result in reversed manner
class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(s[i]=='*'){
                st.pop();//pop * and its previous char
                st.pop();
            }
           
        }
        while(st.size()!=0){ //transfer stack chars to string var
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
