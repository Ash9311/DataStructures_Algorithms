//https://leetcode.com/problems/predict-the-winner/description/
class Solution {
public:

   bool solve(vector<int> &nums,int sum1,int sum2,int turn,int i,int j){
       if(i>j){ //game ended check who has more sum
        if(sum1>=sum2){
            return true;
        }
            return false;
       }

        if(turn){ //if either of 2 calls is true means that player 1 has won
            return solve(nums,sum1+nums[i],sum2,false,i+1,j)||solve(nums,sum1+nums[j],sum2,false,i,j-1);
        }
        else{ //since player 2 will play optimally
            return solve(nums,sum1,sum2+nums[i],true,i+1,j) && solve(nums,sum1,sum2+nums[j],true,i,j-1);//if both r true then it means player 1 won else player 2
        }
        
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,0,true,0,nums.size()-1);
    }
};
