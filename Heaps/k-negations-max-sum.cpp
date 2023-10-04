//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum=0;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        //pop out and change sign of top k index of min heap
        while(k--){
            int top =  pq.top();
            pq.pop(); //important to pop first and then push negation to pq. else it will get messed up,using this logic 
            pq.push(-1*top); //negation operation can also be applied on the same index multiple times, if it remains top at pq
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
