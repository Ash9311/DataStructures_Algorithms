//maintain a max heap priority queue. push all elements first. and then set a condition such that u reach
//kth smallest while popping
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for(int i=0;i<=r;i++){
            pq.push(arr[i]);
        }
        int j=0;
        while(j!=r-k+1){ //finds kth smallest,pq its in descending order
            pq.pop();
            j++;
        }
        return pq.top();
    }
};
