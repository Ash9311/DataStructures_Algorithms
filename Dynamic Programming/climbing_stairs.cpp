//https://leetcode.com/problems/climbing-stairs/

//use  recursive approach with memoization, we are using top down approach, write the base condition, memoize the value

class Solution {
public:
  
    int solve(int n,vector<int> &memo){
        if(n==0) {
            return 1; //means it is in the final path (top down approach)
        }
        if(n<0){
            return 0; //out of range
        }
        if(memo[n]>0){
            return memo[n]; //if already calculated use that value
        }
        memo[n] = solve(n-1,memo) + solve(n-2,memo); //store the result so that we can use for repeating ones
        return memo[n];
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1,0);
        return solve(n,memo);
    }
};
