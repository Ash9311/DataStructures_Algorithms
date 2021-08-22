#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> arr, int i){
    if(i>=arr.size()){
        return true;
    }

    if(arr[i] < arr[i-1]){
        return false;
    }

    return checkSorted(arr,i+1);
}


int main() {
  cout<<"Enter size of array: "<<endl;
  int n;
  cin>>n;

  vector<int> arr(n);
  cout<<"Enter elements: "<<endl;
  for(int i=0; i<n; i++){
      cin>>arr[i];
  }

  cout<<checkSorted(arr, 1)<<endl;
}
