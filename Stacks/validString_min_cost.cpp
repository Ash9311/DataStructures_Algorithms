//https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
//if odd directly return -1. first filter out valid braces, and then count the number of open and closed braces
//and then put it to equation to get the result
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
    if(str.size()%2!=0){
        return -1;
    }
    stack<char>st;
    //take out valid braces
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch=='{'){
            st.push(ch);
        }
        else{
            //ch is closed brace
            if(!st.empty() and st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    //valid parenthesis filtered out, invalid ones left
    //invalid ones can be of type only...{{{{ ,}}}},}}{{
    //take the count of open and closed braces
    int open=0,closed=0;
    while(!st.empty()){
        if(st.top()=='{'){
            open++;
        }
        else{
            closed++;
        }
        st.pop();
    }
    
    int result = (open+1)/2 + (closed+1)/2; //this equation fits for all possible combination of invalid braces
    return result;
}
