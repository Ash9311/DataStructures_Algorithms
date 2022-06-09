//https://leetcode.com/problems/search-in-rotated-sorted-array/
//there are 2 cases one is normal increasing array and the other is when start is greater than end
//[5,6,7,1,2,3,4]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e =nums.size()-1;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[s]<=nums[mid]){
                if(target>=nums[s] and target<=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else if(nums[s]>=nums[mid]){
                if(target>=nums[mid] and target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
