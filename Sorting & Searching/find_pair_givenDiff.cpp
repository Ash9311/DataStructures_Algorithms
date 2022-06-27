//https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1/

//create a map and handle scenario when n=0, case when the target is equal to current element
//it is true only when there is a duplicate

bool findPair(int arr[], int size, int n){
    //code
            
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++){
            mp[arr[i]]++;
        }
        
        for(int i=0;i<size;i++){
            int target = arr[i]-n;
            
            if(n==0 and mp[target]>1){
                return true;
            }
            
            else if(mp[target] and n>0){
                return true;
            }
        }
        return false;
    
}
