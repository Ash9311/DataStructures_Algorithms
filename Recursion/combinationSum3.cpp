//https://leetcode.com/problems/combination-sum-iii/
//make a method to calculate sum of elements in a vector and use recursive to logic to generate a combination of 3
//numbers satisfying the condition
class Solution {
public:
    vector<vector<int>> result;
    
    int sum(vector<int> &ds){
        int ans=0;
        for(auto it:ds){
            ans+=it;
        }
        return ans;
    }
    
    void solve(int k,int n,vector<int> &ds,int i){
        if(k==0 and sum(ds)==n){ //condition met
            result.push_back(ds);
            return;
        }
        if(i>9){
            return;
        }
        ds.push_back(i); //considering the current number
        solve(k-1,n,ds,i+1); 
        ds.pop_back(); //backtrack and explore new combinations
        solve(k,n,ds,i+1); //not considering
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        int sum=0;
        solve(k,n,ds,1);
        return result;
    }
};
