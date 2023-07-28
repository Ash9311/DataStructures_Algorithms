//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
//make a track of left max and right min for arr. and if leftMax<=rightMin[i+1] then we need a compartment to be added. increase count
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightMin(n+1,INT_MAX);

        for(int i=n-1;i>=0;i--){
            rightMin[i] = min(arr[i],rightMin[i+1]);
        }

        int count = 0;
        int leftMax = INT_MIN;
        for(int i=0;i<n;i++){
            leftMax = max(arr[i],leftMax);
            cout<<leftMax<<" "<<rightMin[i+1]<<endl;
            if(leftMax<=rightMin[i+1]){
                count++;
            }
        }
        return count;
    }
};
