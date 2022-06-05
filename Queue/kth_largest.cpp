//https://leetcode.com/problems/kth-largest-element-in-an-array/

make use of max heap priority queue and pop n-l+1 element

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
         int size = nums.size();
        for(auto it: nums){
            pq.push(it);
        }
       
        while(size!=nums.size()-k+1){
            pq.pop();
            size--;
        }
        
        return pq.top();
    }
};
