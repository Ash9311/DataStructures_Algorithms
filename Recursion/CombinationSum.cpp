
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




//https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#
//User function template for C++
// class cmp{
//     public:
//  bool sizecom(const vector<int>& v1, const vector<int>& v2)
// {
    
//     return v1.size() > v2.size();
// }
// };

class Solution {
  public:
  
 
  
  void solve(vector<int> &A,int target,int i,vector<vector<int>> &result,vector<int>&ds){
      if(i==A.size()){
          if(target==0){
              result.push_back(ds);
          }
          return;
      }
      
      if(A[i]<=target){
          ds.push_back(A[i]);
          solve(A,target-A[i],i,result,ds);
          ds.pop_back();
      }
      solve(A,target,i+1,result,ds); 
  }
  
  
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int target) {
        // Your code here
        vector<vector<int>> result;
        vector<int> ds;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end()); //filter duplicate ones
        solve(A,target,0,result,ds);
        return result;
    }
};
