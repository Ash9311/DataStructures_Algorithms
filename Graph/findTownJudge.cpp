//https://leetcode.com/problems/find-the-town-judge/
//count will be equal to n-1 if the person is a townjudge ,satisfying the condition
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1,0);
        for(auto it: trust){
            count[it[0]]--; 
            count[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
