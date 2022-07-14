class Solution {
//maintain a hashmap and check for target element for each element that you traverse       
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> mp;
         vector<int> result;
        
        for(int i=0;i<nums.size();i++){
            int x = target - nums[i];
            if(mp.find(x)!=mp.end()){
                result.push_back(mp[nums[i]]);
                result.push_back(i);
                return {mp[x],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
