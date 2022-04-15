//https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> anagram;
        for(string s: strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        for(auto it:mp){
            anagram.push_back(it.second);
        }
        return anagram;
    }
};
