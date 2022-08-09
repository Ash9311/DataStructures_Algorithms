//https://practice.geeksforgeeks.org/problems/max-rectangle/1
//this is similar to 'largest area in histogram', first compute largestRectangleArea for the first row and then add up the values to the next
//rows. add only if current element is non zero else take it as zero. once you get the added up values compute largestRectangleArea for each row
//and then we get maxArea

class Solution{
    
     private:
vector<int> nextSmallerElement(int *height,int n){
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
    
    vector<int> prevSmallerElement(int *height,int n){
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
 
     int largestRectangleArea(int *heights,int n) {
        int area = INT_MIN;
        vector<int> next(n);
        next = nextSmallerElement(heights,n); // O(N)
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n); // 0(N)
        
        for(int i=0;i<n;i++){
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
    
     public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        //first calculate largestRectangleArea for first row and then add it up to the next row. representing them as a histogram
        //if ith row value is zero then take that as zero itself
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row update: add previous row values
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
            }
            area = max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
    
    
};
