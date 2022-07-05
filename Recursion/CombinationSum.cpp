
//https://leetcode.com/problems/combination-sum/submissions/

//using considering ,not considering logic of recursion find all the combinations and when considering an element subtract it from target
//when the target is zero we get to know that we got the correct combination
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
        combinationSum(candidates,i,target-candidates[i],ds,res); //since we are also including repeated elements we are not incrementing i
        ds.pop_back(); //back track the taken combination so that we can explore new ones
        }
        combinationSum(candidates,i+1,target,ds,res); //explore new index
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        combinationSum(candidates,0,target,ds,res);
        return res;
    }
};
