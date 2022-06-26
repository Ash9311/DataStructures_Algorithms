//https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/

//maitain a hash and traverse through each element starting from second(map first element by default) and
//for others map non duplicate ones and then if the count is equal to row then it means its common for all rows

#include <bits/stdc++.h>
using namespace std;
 

#define row 4
#define col 5

int findCommon(int mat[row][col])
{
    unordered_map<int,int> mp;
    int i,j;
   for(i=0;i<row;i++){
       mp[mat[i][0]]++;
       for(j=1;j<col;j++){
           if(mat[i][j]!=mat[i][j-1]) //appearing for first time in the row
           {
               mp[mat[i][j]]++;
           }
       }
   }
   
   for(auto it:mp){
       if(it.second==row){ //if the count is equal to total row
           return it.first;
       }
   }
   return -1;
}
 
int main()
{
    int mat[row][col] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 2, 9, 11 },
        { 1, 3, 2, 7, 9 },
    };
    int result = findCommon(mat);
    if (result == -1)
        cout << "No common element";
    else
        cout << "Common element is " << result;
 
    return 0;
}
