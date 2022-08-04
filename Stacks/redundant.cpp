//https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1

//push open bracket and other operands in the stack, and if it is ')' then run a while loop and pop the elements until we get
//open bracket, if open bracket is found at first iteration then redundant is detected

#include<stack>

bool findRedundantBrackets(string &s)
{    
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch=='(' or ch=='+' or ch=='-' or ch=='*' or ch=='/'){
            st.push(ch);  
        }
        else{
            if(ch==')'){
                int itr=1;
                while(st.top()!='('){
                    st.pop();
                    itr++;
                }
                if(itr==1){ //it means there is nothing between 2 open and close brackers, therefore redundant detected
                    return true;
                }
                st.pop(); //to pop opening bracket
            }
        }
        
    }
    return false;
}
