//https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

//store the respective numerical sequence of each char in an array, and then for each char subtract with the ascii value of 'A' 
//to get the respective index which can be used to get respective numerical number. if its just a space then add 0

#include <bits/stdc++.h>
using namespace std;
 

string printSequence(string arr[],string input)
{
  int n = input.length();
  string result ="";
  
  for(int i=0;i<n;i++){
      if(input[i]==' '){
          result+='0'; // include zero if its a space
      }
      else{
          int position = input[i] - 'A'; //calculating index based on ASCII value
          result+=arr[position];
      }
  }
  return result;
}
 
// Driver function
int main()
{
    // storing the sequence in array
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
 
    string input = "ASHUTOSH";
    cout << printSequence(str, input);
    return 0;
}
