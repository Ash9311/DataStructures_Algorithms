//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
class Solution {
public:

    bool isPossible(vector<int> &weights,int days,int limit){
        int n = weights.size();
        int daysPassed = 0;
        int totalWeight =0;
        for(int i=0;i<n;i++){
            
            totalWeight +=weights[i];
            if(totalWeight>limit){
               daysPassed++;
                totalWeight=weights[i]; //continue next day with this weight added
                if(daysPassed>=days){
                return false;
            }
            }
        }
        return true;

    }

    int shipWithinDays(vector<int>& weights, int days) {
        //max of all nums is the lower bound and sum of all nums is upperbound. perform binary search on this
        //till you get most optimal answer
        int l=-1;
        int r=0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            l = max(l,weights[i]);
            r+=weights[i];
        }
        int mid;
        while(l<r){
             mid = (l+r)/2;
        
            if(isPossible(weights,days,mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;


    }
};
