//https://practice.geeksforgeeks.org/contest/job-a-thon-10-hiring-challenge/problems/#
//when you swap mismatched numbers within a matrix. 2 mismatched nums will be matched in 1 operation. so ans is mismatchedCount/2. but make sure its even
//count of 1's 0's in both the matrix should be same

class Solution 
{ 
    int count(int N, int A[][], int B[][]) 
    { 
        int oneCountA=0;
        int OneCountB = 0;
        int mismatches = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[i][j]==1){  //track count of 1's
                    oneCountA++;
                }
                if(B[i][j]==1){
                    OneCountB++;
                }
                if(A[i][j] != B[i][j]){ //check if its a match
                   mismatches++;    
                }
            }
        }
        if(oneCountA!=OneCountB){
            return -1;
        }
        if(mismatches%2!=0){
            return -1;
        }
        return mismatches/2;
    }
} 
