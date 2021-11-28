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
