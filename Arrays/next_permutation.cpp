//declare 2 indexes. index1 is that point where the next element is greater while traversing from the end if its not there a reversed array is the ans. if not
//find index2 which is the first greatest element from last w.r.t index1. swap it and reverse as mentioned in line 25.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index1,index2;
        
        for(index1=n-2;index1>=0;index1--){
            if(nums[index1]<nums[index1+1]){
                break;
            }
        }
        
        if(index1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(index2=n-1;index2>index1;index2--){
                if(nums[index2]>nums[index1]){
                    swap(nums[index1],nums[index2]);
                    break;
                }
            }
                reverse(nums.begin()+index1+1,nums.end());
            
        }
    }
};
