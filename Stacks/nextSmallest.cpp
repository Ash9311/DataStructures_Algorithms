//https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1

//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//create a stack and start iterating the arr from last element so that it is efficient
//check if there is any smaller number next to it by checking the stack and also
//we must insert all element that we traverse into the stack
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> result(n,-1);
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){ //starting from last index
        if(st.top()<arr[i]){
            result[i]=st.top();
        }
        else{
            //pop till u get lesser number
            while(st.top()>=arr[i]){ //since we have -1 at bottom
                st.pop(); 
            }
            result[i]=st.top();
        }
        st.push(arr[i]); //make sure you insert to stack
    }
    return result;
}




//use the stack trick to find the next smallest number w.r.t the current number
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> result(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() and arr[st.top()]>arr[i]){ //this logic will maintain the next smallest number in stack
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
     return result;   
    } 
};
