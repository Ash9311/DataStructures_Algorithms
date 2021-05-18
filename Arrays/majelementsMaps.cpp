class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> v;
        for(int num : nums){
            count[num] = count[num] + 1;
            if(count[num]>nums.size()/3){
                if ( !(std::find(v.begin(), v.end(), num) != v.end() ))
                    v.push_back(num);
            }
        }
        return v;
    }
};