class Solution {
public:
    
    int partition(vector<int> &arr,int s,int e){
        int pivot = arr[e];
        int i = s-1; 
        for(int j=s;j<e;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }     
    swap(arr[i+1],arr[e]);
    return i+1;
    }
    
    int quickSelect(vector<int> arr, int s,int e,int k){
        int p = partition(arr,s,e);
        if(p==k){
            return arr[p];
        }
        else if(k<p){
            return quickSelect(arr,s,p-1,k);
        }
        else{
            return quickSelect(arr,p+1,e,k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n =nums.size()-1;
        return quickSelect(nums,1,n,k);
    }
};
