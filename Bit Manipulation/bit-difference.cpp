//https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        const int mod = 1000000007;
        int ans = 0;
        for(int i=0;i<32;i++){
            int count = 0;
            for(int j=0;j<N;j++){
                if(A[j] & 1<<i){ //count set bits in all 32 bits
                    count++;
                }
            } //there will be N-count bits with 0's
            ans+= (count * (N-count)*2); //total permutation is count*(N-count), *2 bcoz of interchangeability
        }
        return ans%mod;
    }
};
