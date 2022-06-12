//https://leetcode.com/problems/valid-anagram/

//maintain a map of char and int. For each iteration increase the count in hashtable of 1 string and decrease in other
//count must be zero at the end or else its not an anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        
        int n  = s.length();
        unordered_map<char,int> counts;
        for(int i=0;i<n;i++){
            counts[s[i]]++;  //increase and decrease count for 2 strings, resultant is expected to be zero if its an anagram
            counts[t[i]]--;
        }
        
        for(auto count: counts){
            if(count.second!=0){
                return false;
            }
        }
        return true;
        
        
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
        
//         if(s==t){
//             return true;
//         }
//         return false;
    }
};
