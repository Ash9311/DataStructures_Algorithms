//https://leetcode.com/problems/largest-rectangle-in-histogram/
//TC - O(N) SC - O(N)
//find the prev and next smaller element for each .and then compute the area for each and keep a track for max area
class Solution {
    
    private:
vector<int> nextSmallerElement(vector<int> height,int n){
    vector<int> ans(n);
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){ //starting from last index
            //pop till u get lesser number
        int curr = height[i];
            while(st.top()!=-1 and height[st.top()]>=curr){ //since we have -1 at bottom
                st.pop(); 
            }
        ans[i]=st.top();
        st.push(i); //make sure you insert to stack
    }
    return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> height,int n){
    vector<int> ans(n);
    stack<int>st;
    st.push(-1);
    for(int i=0;i<n;i++){ //starting from first index
            //pop till u get lesser number
        int curr = height[i];
            while(st.top()!=-1 and height[st.top()]>=curr){ //since we have -1 at bottom
                st.pop(); 
            }
        ans[i]=st.top();
        st.push(i); //make sure you insert to stack
    }
    return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights,n); // O(N)
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n); // 0(N)
        
        for(int i=0;i<n;i++){
            cout<<next[i]<<" "<<prev[i]<<endl;
            int l = heights[i];
            if(next[i] == -1){      //as per out function next to last element is marked as -1 so rectify it
                next[i] = n;
            }
            int b = (next[i] - prev[i] -1); //same length h[i] can be fit in this breadth
            int newArea = l*b;
            area = max(area,newArea);
            // cout<<next[i]<<" "<<prev[i]<<" "<<newArea<<" "<<heights[i]<<endl;
        }
        return area;
        
    }
};
