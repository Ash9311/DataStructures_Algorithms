class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    //declare a new stack and vector res with -1 filled. go through n iterations and push indexes into the stack
    
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> res(n,-1);
        for(int i=0;i<n;i++){
            while(st.size()!=0 and arr[i]>arr[st.top()]){
                res[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
