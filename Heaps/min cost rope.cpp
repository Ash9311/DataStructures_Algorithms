//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
//push all elements to min heap. and then keep on popping 2 elements from top of min heap and add the sum to
//ans
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans=0;
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a+b;
            ans+=sum; //since cost of connecting is the sum itself
            pq.push(sum);
            
        }
        return ans;
    }
};
