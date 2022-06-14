//https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

//make a hash map of char,int iterate through the string and increase the map count and then we will be getting duplicate and its count.
#include <bits/stdc++.h>
using namespace std;
 
// Function which computes the sequence
void printDups(string str)
{
 map<char,int>count;
 
 int n =str.length();
 
 for(int i=0;i<n;i++){
     count[str[i]]++;
 }
  
  for(auto it: count){
      if(it.second>1){
          cout<<it.first<<" "<<it.second<<endl;
      }
  }
 
}
 
// Driver function
int main()
{
  string str = "ashutosh";
  printDups(str);
  return 0;
}
