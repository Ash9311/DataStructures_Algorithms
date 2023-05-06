//https://leetcode.com/problems/find-the-duplicate-number/description/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtle = nums[0];
        int hare = nums[0];
//move turtle variable next to the value of its current index. move hare to the index corresponding to value of cuurent index
        do{
            turtle = nums[turtle];
            hare = nums[nums[hare]];
        }while(turtle!=hare);
//once u find a common number. set hare to nums[0] and move both to its next index corresponding to its current value
        hare = nums[0];
        while(turtle!=hare){
            turtle = nums[turtle];
            hare = nums[hare];
        }
        //the first common number you find is the duplicate

        return turtle;
        

    }
};
