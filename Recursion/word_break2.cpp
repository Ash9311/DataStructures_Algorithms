//https://practice.geeksforgeeks.org/problems/word-break-part-23249/1/#

//initialize a global map of string, int. insert all value of dictionary into it as a key. use recursion to generate all substrings and check if it matched with
//the words we have in the map
class Solution{
   
public:
 map<string,int>freq;
 
 void solve(string s, vector<string> &result,int n, string temp){
     if(s.length()==0){
         temp.pop_back(); //remove xtra space at the end
         result.push_back(temp);
         return;
     }
     for(int i=0;i<s.length();i++){ 
         string substring = s.substr(0,i+1);
         if(freq[substring]){
             substring+=' ';//so that we separate words as asked
             solve(s.substr(i+1),result,n,temp+substring);
         }
     }
 }
 
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(auto it: dict){
            freq[it]++;
        }
        vector<string> result;
        solve(s,result,n,"");
        return result;
    }
};
