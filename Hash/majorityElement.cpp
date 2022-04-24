//https://leetcode.com/problems/majority-element/submissions/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(auto num:nums){
            mp[num] = mp[num]+1;
            if(mp[num]>nums.size()/2){
                return num;
            }
            
        }
        return 0;
    }
};
