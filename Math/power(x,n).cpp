//https://leetcode.com/problems/powx-n/description/
class Solution {
public:
    double myPow(double x, long n) {
        if(n==0){
            return 1;
        }
        if(n<0){ // mathematics. make it -ve and invert power
            n *= -1;
            x = 1/x;
        }
        return n%2==0?myPow(x*x,n/2):x*myPow(x*x,n/2);// example -> (2)^10   (2^2)^5

    }
};
