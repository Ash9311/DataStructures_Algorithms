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
