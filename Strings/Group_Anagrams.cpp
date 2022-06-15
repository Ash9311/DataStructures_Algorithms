//https://leetcode.com/problems/group-anagrams/submissions/

//make a map of string as a key and vector<String> as value. iterate through each given string, sort it, use sorted string as a key and 
// store the anagrams there

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);// sorted string acts as a key, anagrams are values in vector
        }
        
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
