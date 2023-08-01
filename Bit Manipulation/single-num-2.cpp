//https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<32;i++){ //traverses through all 32 buts and each performs operation on all nums
            int bit = 1<<i;
            //cout<<bit<<endl;
            int count = 0;
            for(int j=0;j<n;j++){ //perform bit operation on all num
                if(nums[j] & bit){
                    count++;
                }

            }
            //since it is given that except 1 num all r having 3 dupli.
            if(count%3!=0){ //this indicates that there is a unique number contributing for this bit.
                ans = ans | bit; //make a note of that unique bit
            }
        }
        return ans;
    }
};
