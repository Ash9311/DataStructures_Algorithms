//https://leetcode.com/problems/find-the-duplicate-number/submissions/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                return nums[i];
            }
            mp[nums[i]]++;
        }
        return 0;
    }
};
