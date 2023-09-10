//https://leetcode.com/problems/longest-valid-parentheses/description/
class Solution {
public:
    int longestValidParentheses(string s) {
        	  int maxLen = 0;
    stack<int> st;
    st.push(-1);  // Push -1 onto the stack to serve as a base index.

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) { //case when stack is empty and we have current as ')'
                st.push(i);  // Push the current index as a new base.
            } else {
                maxLen = max(maxLen, i - st.top()); //there is a potential imbalanced par so. just consider the range i - st.top()
            }
        }
    }

    return maxLen;
    }
};
