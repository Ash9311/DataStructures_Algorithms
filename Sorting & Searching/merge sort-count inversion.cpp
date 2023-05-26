//https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=1
//using merge sort we can count the indexes that are greater in value and lower in index while
//sorting

#include <bits/stdc++.h> 

int merge(long long arr[],int temp[],int left,int mid,int right){
    int inv_count = 0;
    int i = left;  //starting of first array
    int j = mid; //starting pointer of second array, since mid+1 is passed
    int k = left; //pointer for temp array

    while((i<mid) && (j<=right)){ //2 pointer approach
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
            inv_count = inv_count + (mid-i); //count all the obvious   elements in between
        }
    }
  //add the remaining either of 2 while will execute
    while(i<mid){ 
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(long long arr[],int temp[],int left,int right){
    int mid,inv_count=0;
   if(right>left){
        mid = (left+right)/2;
        inv_count += mergeSort(arr,temp,left,mid);
        inv_count += mergeSort(arr,temp,mid+1,right);
        inv_count += merge(arr,temp,left,mid+1,right);
   }
   return inv_count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int temp[n];

    return mergeSort(arr,temp,0,n-1);
}
