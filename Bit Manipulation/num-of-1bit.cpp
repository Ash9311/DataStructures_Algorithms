//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
       while(n>0){ //iterate until all bits traversed
      
           if((n&1)>0){ //check parity of 1st bit from right
               count++;
           }
           n = n>>1; //n=n/2, shift one bit to right

       }
       return count;
    }
};
