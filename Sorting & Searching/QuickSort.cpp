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
    
    void quickSort(vector<int> &arr,int s,int e){
        if(s>=e){
            return;
        }
        int p = partition(arr,s,e);
        quickSort(arr,s,p-1);
        quickSort(arr,p+1,e);
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        
       quickSort(nums,0,nums.size()-1);
        return nums;
        
    
}
};
