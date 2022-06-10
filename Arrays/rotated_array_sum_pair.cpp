//https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

//find the pivot element(i.e point where next element is smaller than current (rotating point)). and then use 2 pointer approach to find the pair.
//remember to use %n

    bool pairInSortedRotated(int arr[], int n, int x)
{
        int i;
        for(i=0;i<n;i++){
            if(arr[i]>arr[i+1]){
                break;
            }
        }
        int l = (i+1)%n; //index of smallest element
        int r = i; // index of largest element
        
        while(l!=r){
            if(arr[l]+arr[r]==x){
                return true;
            }
            else if(arr[l]+arr[r]<x){
                l = (l+1)%n;
            }
            else{
                r = (n+r-1)%n;
            }
            return false;
        }
        
        
    }
