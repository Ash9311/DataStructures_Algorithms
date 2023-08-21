//https://leetcode.com/problems/reverse-bits/description/?envType=featured-list&envId=top-interview-questions

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for(int i=31;i>=0;i--){
            if(n&1){  //if that particular bit is set then below logic will give us the reversed one
                result = result | 1<<i;
              }
            n = n>>1;
        }
        return result;
    }
};
