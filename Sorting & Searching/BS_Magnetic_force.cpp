//https://leetcode.com/problems/magnetic-force-between-two-balls/
class Solution {
public:
    
    bool canPlaceBalls(vector<int>& position,int mid,int m){
        int balls = 1;
        int N=position.size();
        int location = position[0];
        for(int i=1;i<=N-1;i++){
            int current_location = position[i];
            if(current_location-location>=mid){
                balls++;
                location = current_location;
                if(balls==m){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    int maxDistance(vector<int>& position, int m) {
     int s=0;
     int N =position.size();
        sort(position.begin(),position.end());
     int e = position[N-1]-position[0];
     int res=0;
      
     while(s<=e){
         int mid = (s+e)/2;
      
         bool canPlace = canPlaceBalls(position,mid,m);
         if(canPlace){
             s = mid+1;
             res=mid;
         }
         else{
             e = mid-1;
         }
     }
        return res;
    }
};
