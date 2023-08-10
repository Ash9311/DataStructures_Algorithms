#include <iostream>

using namespace std;
//start with 1st index and keep prev index track. put in a while loop if u see prev element greater than current  then perform operations
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void insertionSortRecursive(int arr[], int n){
  if(n<=1){
      return;
  }
  insertionSortRecursive(arr,n-1);
  int last = arr[n-1];
  int j = n-2;
  
  while(j>=0 && arr[j]>last){
      arr[j+1] = arr[j];
      j--;
  }
  arr[j+1] = last;
  
}


int main()
{
    int arr[] = {12, 6, 13, 5, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    //insertionSort(arr, n);
    insertionSortRecursive(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  
    return 0;
}
