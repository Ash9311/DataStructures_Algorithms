//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1


//iterate through each char in string, update the map count and push every char to queue.
//if q.front() is not repeating then we found what we need, push it to res else keep popping till q is empty
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    
		    unordered_map<char,int> count;
		    char ch;
		    int i=0;
		    string res = "";
		    for(i=0;i<A.length();i++){
		        ch = A[i];
		        count[ch]++;
		        q.push(ch);
		        
		        //since we are searching for non repeating in entire string. we
		        //need to check the queue where we stored all.
		       while(!q.empty()){
		           if(count[q.front()]>1){
		               q.pop();
		           }
		           else{
		               res.push_back(q.front());
		               break;
		           }
		       }
		        
		        if(q.empty()){
		            res.push_back('#');
		        }
		    }
		    return res;
		}

};




//Approach #2


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
