//https://practice.geeksforgeeks.org/problems/3b47f0ad00f953dd514235ddec54e39fdc297dda/1
//maintain  a stack and iterate through all the char in the string.
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        st.push(-1);
        int maxx=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxx = max(maxx,(i-st.top())); //will get to know the length of that valid substring
                }
            }
        }
        return maxx;
    }
};
