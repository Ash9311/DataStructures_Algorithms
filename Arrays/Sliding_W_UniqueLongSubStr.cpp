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
            
            //update last occurence
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
