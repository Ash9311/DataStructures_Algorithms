
#include<bits/stdc++.h>
using namespace std;
int totalSubset = 0;

int numOfJumps(int n){
    if(n<0){
        return 0;
    }

    if(n==0){
        return 1;
    }

    return numOfJumps(n-1)+numOfJumps(n-2)+numOfJumps(n-3);
}


int main() {
 cout<<"Enter the value of n"<<endl;
 int n;
 cin>>n;

 cout<<"Number of jumps "<<numOfJumps(n)<<endl;
}
