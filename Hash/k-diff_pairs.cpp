//https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int target = nums[i]-k;
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    if(nums[j]==target){
                         if(!(mp.count(nums[i]) and mp[nums[i]]==nums[j])){
                            mp.insert(make_pair(nums[i],nums[j]));
                           // mp[nums[i]]=nums[j];
                            count++;
                         }
                      
                    }
                }
            }
            
        }
        return count;
    }
};
