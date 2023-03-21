//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//start from each index and check if needle is present
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m=needle.size();
    
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(haystack[i+j]!=needle[j]){
                   break;
               }
               if(j==m-1){
                   return i;
               }
           }
           }
            return -1;
       }
    
    };
