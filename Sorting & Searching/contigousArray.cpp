//https://leetcode.com/submissions/detail/1013766723/
//TC - O(n) , SC-O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxx = 0;
        int count = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        //if current index is 1 then increment the count by 1 else -1. so if the sum of count is zero or same in the map. then there is a balanced sub-array
        for(int i=0;i<n;i++){
          if(nums[i]==0){
              count+=-1;
          }
          else{
              count+=1;
          }
          if(count==0){
              //if count is 0 then the subarray from begining is balanced
              maxx = i+1;
          }
          else if(mp.find(count)!=mp.end()){ //if the same sum already exists. it means that somewhere in between there is a subarray fulfilling condition
            maxx = max(maxx,i-mp[count]);
          }
          else{
              mp[count]=i; //store the index for that count
          }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
    return maxx;
    }
};
