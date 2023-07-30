//https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/
//make a map for all num using mod logic and then check if it matches with i,k-i
class Solution {
public:
    int counter[100005];
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            counter[(k+(arr[i]%k))%k]++; //to handle -ve num. it ,makes it positive with addition and % logic
        }
      
      if(counter[0]%2!=0){ //special check for zero bcoz i,k-i isnt valid in case of zero
          return false;
      }

        for(int i=1;i<k;i++){
            if(counter[i]!=counter[k-i]){ //check if count matches
                return false;
            }
        }
        return true;
    }
};
