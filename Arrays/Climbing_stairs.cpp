//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    
     int climbStairs(int n) 
{
     if(n==0 or n==1){
         return 1;
     }
         int stepOne=1;
         int stepTwo=1;
         int result=0;
         
         for(int i=2;i<=n;i++){
             result = stepOne+stepTwo;
             stepTwo=stepOne;
             stepOne=result;
         }
         return result;
 }
    
};
