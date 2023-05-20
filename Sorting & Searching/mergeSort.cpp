//https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    void merge(int arr[], int left, int mid, int right)
    {
         int leftSize = mid - left +1;
         int rightSize = right - mid;
         
         //create temp arrays
         vector<int> leftArr(leftSize);
         vector<int> rightArr(rightSize);
         
         //copy data to temporary arrays
         for(int i=0;i<leftSize;i++){
             leftArr[i]=arr[left+i];
         }
         for(int j=0;j<rightSize;j++){
             rightArr[j]=arr[mid+j+1];
         }
         
         //merge temp arrays back to arr
         int i=0;
         int j =0;
         int k = left;
         
         while(i<leftSize && j<rightSize){ //2 pointer approach sort
             if(leftArr[i] <= rightArr[j]){
                 arr[k] = leftArr[i];
                 i++;
             }
             else{
                 arr[k] = rightArr[j];
                 j++;
             }
             k++;
         }
         
         //include remaining indexes , willl execute either
         while(i<leftSize){
             arr[k] = leftArr[i];
             i++;
             k++;
         }
          while(j<rightSize){
             arr[k] = rightArr[j];
             j++;
             k++;
         }
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        //code here
        if(left<right){
            int middle = left + (right-left)/2;
            //sort first and second halves
            mergeSort(arr,left,middle);
            mergeSort(arr,middle+1,right);
            merge(arr,left,middle,right);
        }
    }
};
--------
    
    
class Solution {
public:
    
     void merge(vector<int> &arr,int s,int e){
            int i = s;
            int mid = (s+e)/2;
            int j = mid+1;
            vector<int> temp;
            while(i<=mid and j<=e){
                if(arr[i]<arr[j]){
                    temp.push_back(arr[i]);
                    i++;
                }
                else{
                    temp.push_back(arr[j]);
                    j++;
                }
            }
            
            while(i<=mid){
                temp.push_back(arr[i++]); //ADD the remainings ..
            }
                                        //any one of these will get executed
             while(j<=e){
                temp.push_back(arr[j++]);
            }
            int k=0;
            for(int idx=s;idx<=e;idx++){ // copy to original
                arr[idx] = temp[k++];
            }
            return;
        }
    
    void mergesort(vector<int>& arr,int s,int e){
            if(s>=e){
                return;
            }
            int mid = (s+e)/2;
            mergesort(arr,s,mid);
            mergesort(arr,mid+1,e);
            return merge(arr,s,e);
        }
    
    
    vector<int> sortArray(vector<int>& nums) {
        
       mergesort(nums,0,nums.size()-1);
        return nums;
        
    
}
};
