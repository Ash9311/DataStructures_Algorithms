//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/

//maintain hashing and handle cases when there is only 1 element and 2 majority elements with differentce of 1 count

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int>mp;
        
        if(size==1){
            return a[0];
        }
        
        for(int i=0;i<size;i++){
            mp[a[i]]++;
        }
        
        for(auto it: mp){
            if(it.second>size/2 and it.second>1){
                return it.first;
            }
        }
        return -1;
        
    }
};
