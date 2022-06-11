//https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/#

//using vector tempInterval keep a track of second element(end) of the range. If an overlap is detected then update the second element of
//tempInterval or else push it to resultant vector and proceed. 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInterval;
        
        if(intervals.size()==0){
            return mergedInterval;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> tempInterval = intervals[0]; // used as a previous vector
        
        for(auto it: intervals){
            if(it[0]<=tempInterval[1]){
                tempInterval[1] = max(it[1], tempInterval[1]); //overlap detected ,update the second index
            }
            else{
                mergedInterval.push_back(tempInterval);// no overlap ,push the pair to the resultant vector;
                tempInterval = it;
            }
        }
        mergedInterval.push_back(tempInterval); // or else last pair that we found wont be considered
        return mergedInterval;
    }
};
