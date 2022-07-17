class Solution {
public:
    //use swapping and recursive approach to find all the permutations, alter the original array and store all combinations in result
    void solve(vector<int> nums,vector<vector<int>> &result,int i){
        if(i==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){ //using swapping and recursion we can generate all combinations
            if(nums[i]==nums[j] and i!=j){
                continue; //skipping repeated chars
            }
            swap(nums[i],nums[j]); 
            solve(nums,result,i+1);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        solve(nums,result,0);
        return result;
    }
};
