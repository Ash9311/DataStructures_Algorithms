//https://leetcode.com/problems/merge-sorted-array/description/
//use 2 pointer approach thats all
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1=0;
        int ptr2=0;
        vector<int> res;
        while(ptr1<m && ptr2<n){
            if(nums1[ptr1]<=nums2[ptr2]){
                res.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                 res.push_back(nums2[ptr2]);
                ptr2++;
            }
          
        }
        while(ptr1<m){ //check for remaining , only 1 of the while loops will get executed
            res.push_back(nums1[ptr1]);
            ptr1++;
        }
        while(ptr2<n){
            res.push_back(nums2[ptr2]);
            ptr2++;
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=res[i];
        }
    }
};
