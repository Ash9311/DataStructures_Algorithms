//T.C - O(N)
//https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

//first compute for the first k sized window. pop from back of queue if you found more max or less min. after that process for remaining k sized
//windows for this make sure you remove indexes that does not belong to the current window. and therefore we get the ans
#include <iostream>
#include<queue>

using namespace std;


int solve(int *arr,int n,int k){
    deque<int>  maxi(k);
    deque<int> mini(k);

    //Addition of 1st k size window
    for(int i=0;i<k;i++){
        while(!maxi.empty() and arr[maxi.back()]<= arr[i]){
            maxi.pop_back();
        }
         while(!mini.empty() and arr[mini.back()]>= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    //ans for 1st window
    ans += arr[maxi.front()] + arr[mini.front()];

    //find for remaining windows
    for(int i=k;i<n;i++){
        
        //removal of elements that does not belong to current window
        while(!maxi.empty() and i-maxi.front()>=k){
            maxi.pop_front();
        }

        while(!mini.empty() and i-mini.front()>=k){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() and arr[maxi.back()]<= arr[i]){
            maxi.pop_back();
        }
         while(!mini.empty() and arr[mini.back()]>= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        //track the ans
        ans += arr[maxi.front()] + arr[mini.front()];
    }

     return ans;
}

 int main(){
    
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k=4;
    cout<<solve(arr,7,k)<<endl;
    return 0;
 }
