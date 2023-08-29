//https://leetcode.com/problems/k-diff-pairs-in-an-array/solutions/1756874/c-multiple-approaches-maps-two-pointer/
// We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
// In this approach , first we sort the array and maintain 2 pointers.

// 1st Pointer --> 1st Element of the Pair
// 2nd Pointer --> 2nd Element of the Pair
// We set the 1st pointer at the 0th index and 2nd pointer at the 1st index. Then ,

// Move the 2nd pointer until 2nd pointer - 1st pointer >=k .
// If the 2nd pointer - 1st pointer ==k , then increment the answer and move the 2nd pointer to the next greater element.
// Move the 1st pointer to the next greater element.
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      
        int n = nums.size();
        int i = 0, j = 1;
        set<vector<int>>s;
        sort(nums.begin(), nums.end());

        while (i < n && j < n) { 
            if (i == j || (nums[j] - nums[i]) < k) {
                j++;
            } else {
                if (nums[j] - nums[i] == k) {
                     s.insert({nums[j],nums[i]}); //to avoid dupli combination
                }
                i++;
                while (i < j && nums[i] == nums[i - 1]) {
                    i++; // skip duplicates
                }
            }
        }

        return s.size();
     }
    
};
