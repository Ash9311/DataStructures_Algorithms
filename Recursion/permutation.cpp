
#include<bits/stdc++.h>
using namespace std;

void getPermutation(string str, int index){
    if(index==str.length()){
        cout<<str<<endl;
        return;
    }

    for(int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        getPermutation(str,index+1);
        swap(str[index],str[i]);
    }
    
}

int main() {
 cout<<"Enter a String"<<endl;
 string str;
 cin>>str;
string output="";
 cout<<"Printing all Permutation"<<endl;
 getPermutation(str, 0);

}
