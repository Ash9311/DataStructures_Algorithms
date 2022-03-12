class Solution {
    
    int binarySearch(vector<int> &nums,int start,int end,int n,int target){
        if(start<=end){
        int mid = (start+end)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                return binarySearch(nums, start, mid-1,n, target);
            }
            else{
                return binarySearch(nums,mid+1, end, n,target);
            }
        }
        return -1;
    }
    
    
    
    
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int n = nums.size();
        int end=n-1;
        return binarySearch(nums,start,end,n,target);
    }
};
