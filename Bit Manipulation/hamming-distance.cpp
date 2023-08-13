//https://leetcode.com/problems/total-hamming-distance/description/
// For each bit position 1-32 in a 32-bit integer belonging to the array, we count the number of integers in the array which have that bit set.

// Then, if there are n integers in the array and k of them have a particular bit set and (n-k) do not, then that bit contributes nx(n-k) to the hamming distance. (Because for each of the 'k' numbers, we have 1 of the (n-k) numbers, that have a different bit and the number of ways to select 1 from k and (n-k) numbers is (kC1)x((n-k)C1)

// Time Complexity : O(n)

// Space Complexity : O(1)

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
  
        int n = nums.size();
        for(int i=0;i<32;i++){ //iterate through all bit and count 1's bit
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[j] & 1<<i){
                    count++;
                }
            } //there will be 'count' 1's and 'n-count' in that particular bit column
           ans= ans+ (count*(n-count));  // countC1)x((n-count)C1)  combinations 
        }
        return ans;
    }
};
