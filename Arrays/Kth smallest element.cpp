//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//use a priority queue which by default sorts by decreasing order, multiply it by -1 so that we get smallest one first

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n = r+1; 
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++){
            int temp = arr[i] *(-1);
            pq.push(temp);
        }
        
        int i=1;
        int result;
        while(i!=k){
            pq.pop();
            i++;
        }
        result = pq.top()*(-1);
        return result;
    }
};
