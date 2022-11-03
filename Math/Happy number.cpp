//https://leetcode.com/problems/happy-number/
//implement a nested while loop where we find sum of square of each digit and continue the process until
//a certain condition is met

/* 
	let's try different n:
	true  (1) -> 1
	false (2) -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 -> 20 -> 4   //4 is the root cause
	false (3) -> 9 -> 81 -> 65 -> 61 -> 37 (look at 2)
	false (4) -> (look at 2)
	false (5) -> 25 -> 29 -> 85 -> 89 (look at 2)
	false (6) -> 36 -> 45 -> 41 -> 17 -> 50 -> 25  (look at 5)
	true  (7) -> 49 -> 97 -> 10
	false (8) -> 64 -> 52 -> 29 (look at 5)
	false (9) -> 9 -> 81 -> 65 (look at 3)
    */
class Solution {
public:
    bool isHappy(int n) {
        
        while(n!=1){
            int temp = n;
            long long sum=0;
            while(temp>0){
                int rem = temp%10;
                temp /= 10;
                sum += rem*rem;
            }
            if(sum==4){ //through dry run v found that 4 chains up to be not a happy number
                return false;
            }
            n = sum;
        }
            return true;
    }
};
