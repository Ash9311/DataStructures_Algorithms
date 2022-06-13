//https://leetcode.com/problems/longest-common-prefix/

//take the first element of str vector and use a for loop starting from next element and see where the substring is commong while reducing it

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0){
            return "";
        }
        string prefix=strs[0];
      for(int i=1;i<strs.size();i++){
          while(strs[i].find(prefix)!=0){
              prefix = prefix.substr(0,prefix.length()-1);
            //flower flowe flow flo..............(when prefix is printed in each iteration)
          }
      }
        return prefix;
    }
};
