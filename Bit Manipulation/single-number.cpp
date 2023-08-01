//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){ //xor of a number on itself is 0. therefore 2-duplicates cancel out. whatever remains is our ans
            res = res^nums[i];
        }
        return res;
    }
};
