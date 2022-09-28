//https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//use a min heap, insert all sub array sum into it. make sure min heap size is less than K. the top element of min heap is our required ans.
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> mini;
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j]; //each and every combination is added to min heap
            if(mini.size()<k){ //since we need kth largest. it needs to b at top
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){ //update if larger num is present
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}
