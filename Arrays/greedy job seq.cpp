/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
//sort the arr according to desc order of profit. find out the max deadline and create a slot array marking as -1.
//iterate through arr and for each put a nested for loop with deadline decreasing. and get the max job profit
class Solution 
{
    public:
    bool static comparison(Job a,Job b){
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
         sort(arr, arr + n, comparison);
         int maxi = arr[0].dead;
         for(int i=0;i<n;i++){
             maxi = max(maxi,arr[i].dead);
         }
         int slot[maxi+1];
         for(int i=0;i<=maxi;i++){
             slot[i] = -1;
         }
         int countJobs = 0;
         int jobProfit = 0;
         for(int i=0;i<n;i++){
             for(int j=arr[i].dead;j>0;j--){
             if(slot[j]==-1){
                 slot[j]=i;
                 countJobs++;
                 jobProfit+=arr[i].profit;
                 break;
             }
             }
         }
         vector<int> result;
         result.push_back(countJobs);
         result.push_back(jobProfit);
         return result;
    } 
};
