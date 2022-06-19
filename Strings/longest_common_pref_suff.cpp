//https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#

maintain a streak array, set the 2 pointers for traversal.

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	 int n = s.length();
	 int streak[n]={0};
	 int ptr2 =1;
	 int ptr1 = 0;
	 
	 while(ptr2<n){
	     if(s[ptr1]==s[ptr2]){
	         ptr1++;
	         streak[ptr2]=ptr1;
	         ptr2++;
	     }
	     else{
	         if(ptr1==0){
	             streak[ptr2]=0;
	             ptr2++;
	         }
	         else{
	             ptr1=streak[ptr1-1];
	         }
	     }
	 }
	 
// 	 for(int i=0;i<n;i++){
// 	    For Input: acccbaaacccbaac
//      Your Output: //it carries the streaks and the latest one is the answer because previous one doesnt include last char
//      0 0 0 0 0 1 1 1 2 3 4 5 6 7 2 2
// 	     cout<<streak[i]<<" ";
// 	 }
	 
	 return streak[n-1];
        
