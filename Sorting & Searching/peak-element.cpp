//https://leetcode.com/problems/find-peak-element/description/
//perfrom binary search and compare mid,mid+1 and change start,end index accordingly
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;

        while(s<e){
            int mid = (s+e)/2;
            if(nums[mid]>nums[mid+1]){ //using this log. v'l get the first peak by the time s<e breaks
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return e; //s,e will be the same
    }
};
