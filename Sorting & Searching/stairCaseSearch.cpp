You are given a Mx N matrix which is row wise and column wise sorted. You have to search the
index of a given integer K in the matrix.
  
Input Format:
Function contains integer M, integer N, 2D vector containing integers and an integer k.
  
Output Format:
Return a pair of integers {x,y} where x is the row index and y is column index of k in the matrix.
Expected Complexity:
Linear
Sample Testcase:
Input:
33
149
2 5 10
6 7 11
10

  output = {1,2}

#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    int i=m-1;
    int j=0;
    while(i>=0 and j<n){
        if(v[i][j]<k){
            j++;
            
        }
        else if(v[i][j]>k){
            i--;
        }
        else{
            break;
        }
    }
    pair<int,int> p = {i,j};
    return p;
    
}
