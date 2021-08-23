
#include<bits/stdc++.h>
using namespace std;

void getSubsequence(string str, int strIndex, string output){
    if(strIndex==str.length()){
        cout<<output<<endl;
        return;
    }
    //not considering
    getSubsequence(str,  strIndex+1, output);

    //considering
    output.push_back(str[strIndex]);
    getSubsequence(str, strIndex+1, output);

}

int main() {
 cout<<"Enter a String"<<endl;
 string str;
 cin>>str;
string output="";
 cout<<"Printing all Sub Sequence"<<endl;
 getSubsequence(str, 0, output);

}
