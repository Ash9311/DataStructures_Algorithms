//https://leetcode.com/problems/combination-sum-ii/submissions/
class Solution {
public:
    
    void findCombinations(vector<int> &candidates,int target,vector<vector<int>> &res,int ind,vector<int> &ds){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind and candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            
            ds.push_back(candidates[i]);
            findCombinations(candidates,target-candidates[i],res,i+1,ds);
            ds.pop_back();
             
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        int ind=0;
        findCombinations(candidates,target,res,ind,ds);
        return res;
    }
};
