//https://leetcode.com/problems/fibonacci-number/
//T.C -> O(N)  S.C -> O(1)
class Solution {
public:
    int fib(int n) {      
        if(n<2){ //base condition
            return n;
        }
        int prev2 = 0;
        int prev = 1; //using variable names for space optimization instead of arrays
        int curr;
        int i;
        for(i=2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
