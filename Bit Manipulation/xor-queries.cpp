//https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        vector<int> xorPrefix(n);
        xorPrefix[0]=arr[0];
        for(int i=1;i<n;i++){ //maintain a prefix array of xors. to make it efficent O(m+n)
            xorPrefix[i] = arr[i]^xorPrefix[i-1];
        }
        for(auto query: queries){
            int i = query[0];
            int j = query[1];
            int op;
            if(i==0){
                op = xorPrefix[j]^0;
            }
            else{
             op=xorPrefix[j]^xorPrefix[i-1]; //since v r having prefixes. xor it with 1 index prior to starting so get in between prefix
            }
            ans.push_back(op);
        }
        return ans;
    }
};
