//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
//store pair of arrival and departure into vector pair
// sort vector pair as per the arrival time of trains
// get min heap
// if lowest departure time in existing platform queue is less
//      than arrival time of new train then pop that train and add new train's departure time
// else add new trains departure time to queue : assigning new platform to new train.
// return size of platform queue.

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    vector<pair<int,int>>TrainsTime;
    	for(int i=0;i<n;i++){
    	    TrainsTime.push_back({arr[i],dep[i]});
    	}
    	
    	sort(TrainsTime.begin(),TrainsTime.end());
    	priority_queue<int,vector<int>,greater<int>> pq;
    	
    	for(int i=0;i<n;i++){
    	    pq.push(TrainsTime[i].second);
    	    if(pq.top()<TrainsTime[i].first){ //arrival time is after departure of prev train so no issues
    	        pq.pop();
    	    }
    	}
    	
    	return pq.size(); //whatever remains in the PQ results the num of new platforms needed
    }
};
