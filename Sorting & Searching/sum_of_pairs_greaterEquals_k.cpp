//https://practice.geeksforgeeks.org/problems/permutations-in-array1747/1/#

//sort one array in ascending order and another on descending and then compare the sum of respective index.

class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n,greater<int>()); //sorts in descending
      
        for(int i=0;i<n;i++){
            if((a[i]+b[i])<k){
                return false;
            }
        }
        return true;
    }
};
