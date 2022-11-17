//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1
//write base condition, define dp array and store the result on it. and check if the result is already present in dp array. use recursively
//run for 1 step and 2 step jump
#include<bits/stdc++.h>

int f(int ind, vector<int> &heights,vector<int> &dp){
    if(ind==0){ //base case
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    
    int left = f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    
    if(ind>1){ //or else it will go to negative index
   		 right = f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(left,right); //store the result in dp array
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}




//tabulation method

#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
   int prev=0;
    int prev2=0;
    
    for(int i=1;i<n;i++){
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
         ss = prev2 + abs(heights[i]-heights[i-2]);
        }
        int curr = min(fs,ss);
        prev2=prev;
        prev = curr;   
    }
    return prev;
}


// k jump case

int frog_k_dp_opt(int n,vector<int> &arr,int k){
    
    vector<int> dp(k+1,0);
    
    
    for(int i=1;i<n;i++){
        int min_energy= INT_MAX;
        for(int j=1;j<=k && i>=j;j++){
            int jump = dp[j]+ abs(arr[i]-arr[i-j]);
            
            min_energy= min(jump,min_energy);
            for(int x=1;x<k;x++){
                dp[x]=dp[x+1];
            }
            
        }
        dp[k]=min_energy;
        
    }
    return dp[k];
}
