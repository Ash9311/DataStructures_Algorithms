//common elements in 2 distinct vecttors
#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    sort(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());
     vector<int> res;
     unordered_map<int,bool> map;
     for(auto it:v1){
         map[it]=true;
     }
     for(auto it:v2){
         if(map[it]==true){
             res.push_back(it);
         }
     }
     return res;
    
   
}
