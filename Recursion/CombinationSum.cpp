//https://leetcode.com/problems/combination-sum/submissions/
class Solution {
public:
    void combinationSum(vector<int> &candidates,int i,int target,vector<int> &ds,vector<vector<int>> &res){
        if(i==candidates.size()){
            if(target==0){
            res.push_back(ds);
        }
            return;
        }
        if(candidates[i]<=target){
        ds.push_back(candidates[i]);
        combinationSum(candidates,i,target-candidates[i],ds,res);
        ds.pop_back();
        }
        combinationSum(candidates,i+1,target,ds,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        combinationSum(candidates,0,target,ds,res);
        return res;
    }
};
