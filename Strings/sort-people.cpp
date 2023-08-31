class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>pq;
        for(int i=0;i<names.size();i++){ //create a pq that stores height in decreasing order
            pq.push({heights[i],names[i]});
        }
        vector<string> ans;
         for(int i=0;i<names.size();i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
