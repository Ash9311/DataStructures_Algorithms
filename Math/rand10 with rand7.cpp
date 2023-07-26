// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
       int x = rand7();
        int y= rand7();
        int pos = (x-1)*7 + y; //so that v get random num in range of 1 to 49 with equal probability
        if(pos>=41){ //when mapped with 10 probability is not equal aftr 41 so recursion
            return rand10();
        }
        return pos%10 + 1; //will return random num between 1 to 10
    }
};
