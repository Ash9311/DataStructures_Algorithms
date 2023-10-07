//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         int ans = 1;
        int prev = INT_MIN; //edge case. inputs can be in -ve

         vector<pair<int,int>> v;
         
        int n = points.size();
        for(int i=0;i<n;i++){
            v.push_back({points[i][1],points[i][0]}); //we are going to sort as per end time(greedy).
        } 
        sort(v.begin(),v.end());
        prev=v[0].first; //take in first one and proceed with rest
        for(int i=1;i<n;i++){
            int start = v[i].second;
            if(start>prev){ //make sure start is before end of previous
                ans++;
                prev = v[i].first;
            }
        }
        return ans;
    }
};
