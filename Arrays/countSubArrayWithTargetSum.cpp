#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    //complete this method
    int n = arr.size();
    unordered_map<int,int> prevSum;
    int currSum=0;
    int res= 0;
    
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        
        if(currSum==k){
            res++;
        }
        
        if(prevSum.find(currSum-k)!=prevSum.end()){
            res+=prevSum[currSum-k];
        }
        prevSum[currSum]++;
    }
    return res;
}
