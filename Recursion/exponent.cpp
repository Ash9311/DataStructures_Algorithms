#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int exp(int n){
    if(n==0){
        return 1;
    }

    int small_ans = exp(n/2);

    if(n&1){
        return 2*small_ans*small_ans;
    }
    else{
        return small_ans*small_ans;
    }
}

int expTwo(int n ){
    if(n==0){
        return 1;
    }

    int ans = 2*expTwo(n-1);
    cout<<" for n "<<n<<" ans "<<ans<<endl;
    return ans;
}

int main(){
    std::cout << expTwo(4) << std::endl;
}
