
//https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// User function Template for C++
//first merge 2 vector and then heapify the resultant
class Solution{
    public:
    void heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int left = i*2+1; //formula for 0 based indexing
    int right = (2*i)+2;
    if(left<=n and arr[largest]<arr[left]){ //check if left and right child is larger, if yes then update,take care of boundary
        largest = left;  
    }
    if(right<=n and arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){ //if updated
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //step 1 : merge both arrays
        vector<int> mergedHeap;
        for(int i=0;i<a.size();i++){
            mergedHeap.push_back(a[i]);
        }
         for(int i=0;i<b.size();i++){
            mergedHeap.push_back(b[i]);
        }
        int N = mergedHeap.size();
        
        for(int i=N/2-1;i>=0;i--){
             heapify(mergedHeap,mergedHeap.size()-1,i);
        }
        //reason y v run heapify in a loop of N/2. find the dry run below,swapping takes place
//         10 5 9 2 12 7 6 
//         10 12 9 2 5 7 6 
//         12 10 9 2 5 7 6 
        return mergedHeap;
        
    }
};
