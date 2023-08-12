//https://leetcode.com/problems/permutations/
class Solution {
public:
    
    void findAllPermutations(vector<int> &nums,vector<int> &freq,vector<vector<int>> &res,vector<int> &ds){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                findAllPermutations(nums,freq,res,ds);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
      
        findAllPermutations(nums,freq,res,ds);
        return res;
    }
};

-----------------------------------
    
class Solution {
public:
vector<vector<int>> ans;
void permutation(int ind,vector<int> nums){
  if(ind==nums.size()-1){ //once ind reaches end then v r done
    ans.push_back(nums);
    return;
  }
  for(int i=ind;i<nums.size();i++){ //swap starting from current index to generate all combinations
      swap(nums[i],nums[ind]);
      permutation(ind+1,nums);
      swap(nums[i],nums[ind]); //backtrack
  }
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        permutation(0,nums);
        return ans;
    }
};
