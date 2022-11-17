//https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
#include <bits/stdc++.h> 

//there are 2 cases. one is excluding first index and other is excluding last index. so check both and return the max one

//same logic as maximumNonAdjacentSum question
long long int maximumNonAdjacentSum(vector<long long int> &nums){
     long long int n =nums.size();
    long long int prev = nums[0]; //base condition
    long long int prev2 = 0;
    for(long long int i=1;i<n;i++){
        long long int pick = nums[i];
        if(i>1){ //edge case
            pick +=prev2; //prev2 bcz v cant pick adjacent one
        }
        long long int nopick = 0 + prev; //pick adj one if not picking current
        long long int curr = max(pick,nopick);
        prev2 = prev; //update and move forward
        prev = curr;   
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    long long int n = valueInHouse.size();
    vector<long long int> case1,case2;
    if(n==1){
        return valueInHouse[0];
    }
    for(long long int i=0;i<n;i++){
        if(i!=0){
            case1.push_back(valueInHouse[i]);
        }
         if(i!=n-1){
            case2.push_back(valueInHouse[i]);
         }
    }
    return max(maximumNonAdjacentSum(case1),maximumNonAdjacentSum(case2));
}
