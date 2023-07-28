//check each num and traverse each num from 2 to sqrt of that num
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum=1+nums[i]; //1 and number itself is always the divisor
            count = 0;
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    count++;
                    sum+=j;

                     if (j != sqrt(nums[i])) { // To avoid duplicate divisor for perfect squares, since we r only traversing till sqrt n
                    count++; //ex - divisors of 21 are 1,3,7,21  
                    sum += nums[i] / j;  // 21/3 is 7 amd 21/7 is 3. so its sort of vice versa. therefore we can just traverse till sqrt(nums[i])
                }
                }
                if(count>2){
                    break;
                }
                  
            }
            if(count==2){
                ans+=sum;
            }
            
        }
        return ans;
    }
};
