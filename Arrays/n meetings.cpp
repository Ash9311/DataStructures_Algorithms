//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
//create a pair of vectors storing end time,start time. sort it and greedyly we can find the max no. of meetings
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int maxx = 1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        
        int lastMeet = v[0].first; //store it since we are starting from 2nd
        for(int i=1;i<n;i++){
            if(lastMeet<v[i].second){ //time validation
                maxx++;
                lastMeet = v[i].first;
            }
        }
        return maxx;
    }
};
