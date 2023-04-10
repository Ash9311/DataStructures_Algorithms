//https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res=0;
   
        for(char c: columnTitle){ //iterate through each char
           int d = c - 'A' + 1; //take out the order of the char using ASCII
           res =  res*26 +d;  //plug in the combination formula
          
        }
        return res;
    }
};
