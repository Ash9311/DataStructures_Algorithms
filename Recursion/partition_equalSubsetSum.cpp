//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//first find the sum and then set sum/2 as a target. and then use recursive approach to find all the subset combination varying the target as
//we are including the element or not
class Solution{
public:

int solve(int arr[],int n,int target){
    if(target==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
   
    if(arr[n-1]<=target){ //we can take it only if its lesser
        return solve(arr,n-1,target-arr[n-1]) or solve(arr,n-1,target);
    }
    return solve(arr,n-1,target);
}
    int equalPartition(int N, int arr[])
    {
          int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        return solve(arr,N,sum/2); //if we find sum/2 then it means there is bound to be one more same
    }
};
