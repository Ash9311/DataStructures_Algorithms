//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    int freq[27] = {0};
		    char ch;
		    int i=0;
		    string res = "";
		    while(A[i]!=NULL){
		        q.push(A[i]);
		        freq[A[i] - 'a']++;
		         while(!q.empty()){
		             int idx = q.front()-'a';
		             if(freq[idx]>1){
		                 q.pop();
		             }
		             else{
		                 res+=q.front();
		                 break;
		             }
		         }
		         if(q.empty()){
		             res+="#";
		         }
		         i++;
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
