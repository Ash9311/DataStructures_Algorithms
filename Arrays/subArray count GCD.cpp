//https://practice.geeksforgeeks.org/contest/job-a-thon-12-hiring-challenge/problems/
//use bruteforce approach and iterate in a sliding window manner and maitain a set to store
//gcd . break out if u find any dupli. return the count
class Solution {
  public:

    long long solve(int N, vector<int> &A) {
       int count=0;
        for(int i=0;i<N;i++){
             set<int> sett; //using a set to track duplicates
            int gcd = 0;
            for(int j=i;j<N;j++){
                gcd = __gcd(gcd,A[j]);
                if(sett.find(gcd)!=sett.end()){ //if its already there then break out
                    break;
                }
                sett.insert(gcd);
                count++;
            }
        }
        return count;
    }
};
