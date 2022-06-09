//https://leetcode.com/problems/3sum/submissions/

iterate through each element and use 2 pointer approach to find the sum and also must handle duplicate numbers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue; //to eliminate duplicates
            }
            int j = i+1;
            int k = n-1;
           
            while(j<k){
                
                int sum = nums[i]+nums[j]+nums[k];
    
                if(sum==0){
                    result.push_back({nums[i],nums[j],nums[k]});
                     while (nums[j]==nums[j+1]){
                         j++;//to eliminate duplicates
                     }
                while (nums[k]==nums[k-1]){
                     k--;//to eliminate duplicates
                }
                     j++;
                     k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return result;
    }
};





//approach 2

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //[-4,-1,-1,0,1,2]
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                
                if(sum==0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }   
            }
        }
        //filters out duplicate vectors in 2D vector
        result.erase(std::unique(result.begin(), result.end()), result.end());
        return result;
    }
};
