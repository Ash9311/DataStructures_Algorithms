//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq; //ex - <sum,{nums1[i],nums2[i]}>
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){ //compute all sum pair and see if it fits in a k sized PQ
                int sum = nums1[i]+nums2[j];
                if(pq.size()<k){  
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(sum<pq.top().first){ //max heap it is
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0){ //fetch the required data that v need to return

            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
