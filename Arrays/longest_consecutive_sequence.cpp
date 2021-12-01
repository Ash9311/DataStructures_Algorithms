//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> set;
        int n = nums.size();
        int count=1;
        vector<int> result;
        
        for(int it: nums){
            set.insert(it);
        }
        int largest=1;
        for(int i : set){
            int parent = i-1;
            count=1;
            if(set.find(parent)==set.end()){
                int next = i+1;
                while(set.find(next)!=set.end()){
                    next++;
                    count++;
                }
                largest = max(count,largest);
            }
        }
        return largest;
    }
};
