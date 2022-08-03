//https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1
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
