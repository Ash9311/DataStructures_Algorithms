// Author - Ashutosh Mulky

#include<bits/stdc++.h>
#include <iostream>
#define izanami while(true)
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define PI 3.1415926535
#define F first
#define S second
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)       
#define ps(s) printf("%s\n",s)
#define pb push_back
#define mk make_pair

using namespace std;

void housing(int *arr, int n, int k){
    int i=0,j=0,sum=0;
    vector<pair<int,int>> result;
    vector<int> ans;
    int minn = INT_MAX;
    while(j<n){
        sum += arr[j];
        j++;
        
        while(sum>k and j>i){
            sum -= arr[i];
            i++;
        }
        
        if(sum==k){
            // cout<<i<<"--"<<j-1; //sum only contains till j-1 so
            result.push_back(make_pair(i,j-1));
            
        }
    }
    for(auto it: result){
        cout<<it.first<<" "<<it.second;
        std::cout << "" << std::endl;
    }
}


int main(){
  int plots[] = {1,3,2,1,4,1,3,2,1,1};
  int n = sizeof(plots)/sizeof(int);
  int k =8;
  housing(plots,n,k);
  
}
