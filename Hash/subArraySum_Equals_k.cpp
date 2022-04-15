//https://leetcode.com/problems/subarray-sum-equals-k/submissions/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum]=1;
        for(auto it:nums){
            sum+=it;
            int target = sum-k;
            if(mp.find(target)!=mp.end()){
                ans+=mp[target];
            }
            mp[sum]++;
        }
         return ans;
    }
};
