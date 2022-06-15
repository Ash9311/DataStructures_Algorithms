//https://leetcode.com/problems/longest-substring-without-repeating-characters/

maintain a set,make 2 references i.e i,j keep i fixed and move j forward. traverse through the array and see if there is a duplicate

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i=0,j=0,ans=0;
        int n = s.size();
        while(j<n){
            if(set.find(s[j])==set.end()){ //repeating char not found
                set.insert(s[j]);
                j++;
                ans = max(ans,j-i);
            }
            else{                   //repeating char is found
                set.erase(s[i]); //erase it so that it doesnt interrupt in next substring
                i++;
            }
        }
        return ans;
    }
};







//sliding window approace

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int> map;
        int window_len =0;
        int max = 0;
        int start_window=i;
        while(j<s.length()){
            char ch = s[j];
            
            if(map.count(ch) and map[ch]>=i){
               i = map[ch]+1;
               window_len = j-i;
            }
            
            map[ch] =j;
            window_len++;         
            j++;
            
            if(window_len > max){
                max = window_len;
                start_window = i;
            }
            
        }
        return max;
    } 
};
