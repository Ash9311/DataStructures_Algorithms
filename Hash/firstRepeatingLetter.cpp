#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    
    unordered_map<int,bool>mp;
    
    for(auto it: input){
        if(mp[it]==1){
            return it;
        }
        mp[it]++;
    }
}
