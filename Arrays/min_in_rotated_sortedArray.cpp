//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//not a normal binary search, since its a rotated array series of continous mid element will be larger than the element which comes after it. 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};
