#include<bits/stdc++.h>
#include<sstream>
#include <iostream>
using namespace std;

int main() {
	string input;
    getline(cin,input);

    stringstream ss(input); // uses << >> operatot
    string token;
    vector<string> tokens;
    while(getline(ss,token,' ')){  //inserts strings in token
        tokens.push_back(token);

    }
     for(string it: tokens ){
         cout<<it<<",";
         

     }

}

