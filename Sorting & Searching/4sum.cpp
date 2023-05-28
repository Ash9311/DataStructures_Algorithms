//use 3 nested loop to iterate through first 3 combinations. and for the 4th integer v'l use hashset and find the target
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> hashset; //to find  4th num and to avoid dupli
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k]; //to prevent integer overflow adding it separately
                    long long fourth = target - sum;
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
