//https://leetcode.com/problems/palindromic-substrings/
//implement a recusive way of finding palindrome in a for loop and also handle even and odd length of palindrome that you find
class Solution {
    int count=1;
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            checkPalindrome(s,i,i);  //check palindrome of odd length palindromic substring
            checkPalindrome(s,i,i+1); //check palindrome of even length palindromic substring
        }
        return count;
    }
    
   void checkPalindrome(string s, int i,int j){
        while(i>=0 and j<s.length() and s[i]==s[j]){
            count++; ///increment since its a palindrome
            i--; // trace left substring
            j++; // trace right substring
        }
    }
    
};
