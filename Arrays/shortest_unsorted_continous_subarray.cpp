// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int flag=0;
    void solve(vector<int>& v,int &largest,int &smallest,vector<int>& nums,int &i){
        flag=1;
        v.push_back(nums[i]);
        largest = max(largest,nums[i]);
        smallest = min(smallest,nums[i]);
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        int smallest = INT_MAX; 
        vector<int> v;
        if(n==1){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            if(i==0){
                 if(nums[i]>nums[i+1]){
                    solve(v,largest,smallest,nums,i);
                     continue;
                }
            }
            else if(i==n-1){
                if(nums[i]<nums[i-1]){
                    solve(v,largest,smallest,nums,i);
                }
                continue;
            }
             
            else if(nums[i]>nums[i+1] || nums[i]<nums[i-1]){
                solve(v,largest,smallest,nums,i);
            }
        }
 
        if(flag==0){
            return 0;
        }
      

        int left=0;
        while(smallest>=nums[left]){
            left++;
        }
        int right = n-1;
        while(largest<=nums[right]){
            right--;
        }
        
        return right-left+1;
    }
};
