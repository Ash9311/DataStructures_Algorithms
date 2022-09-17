//https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <bits/stdc++.h> 
//iterate through nodes check condition for left and right child also check if child is within boundary
//swap if condition is not met and use recursion to traverse for all
void heapify(vector<int> &arr,int n,int i){
    int smallest = i;
    int left = i*2 + 1; //formula inccase of 9 based indexing
    int right = (2*i)+2;
    if(left<n and arr[smallest]>arr[left]){ //check if left and right child is larger, if yes then update,take care of boundary
        smallest = left;  
    }
    if(right<n and arr[smallest]>arr[right]){
        smallest = right;
    }

    if(smallest!=i){ //if updated
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest); //recursively traverse for all nodes
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    vector<int> res;
    int n= arr.size();
    for(int i=n/2-1; i>=0;i--){
    heapify(arr,n,i);     
} //arr is passed as ref and we get out required ans stored in it
    return arr;
}
