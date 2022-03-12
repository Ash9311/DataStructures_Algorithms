//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5235660#questions
#include<bits/stdc++.h>
using namespace std;

bool divideAmongK(vector<int> &arr,int n,int k, int min_coins){
    int partitions=0;
    int current_friend = 0;
    for(int i=0;i<n;i++){
        if(current_friend+arr[i]>=min_coins){
            partitions+=1;
            current_friend=0;
        }
        else{
            current_friend+=arr[i];
        }
    }
    return partitions>=k;
}


int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    int s=0;
    int n = arr.size();
    int e=0,ans=0;
    for(auto it:arr){
        e+=it;
    }
    while(s<=e){
       int mid=(s+e)/2;
        bool ispossible = divideAmongK(arr,n,k,mid);
        if(ispossible){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
    
    
}
