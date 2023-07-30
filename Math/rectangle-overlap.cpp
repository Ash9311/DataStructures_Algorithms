//https://leetcode.com/problems/rectangle-area/description/
//calculate total area of 2 rectangles. and find xoverlap,yoverlap using max,min logic of coordinates and subtract overlaped area from total and return the ans
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = (ax2-ax1)*(ay2-ay1);
        int bArea = (bx2-bx1)*(by2-by1);

        int overlap = 0;

        int xOverlap =min(ax2,bx2)-max(bx1,ax1); // 3 - 0
        int yOverlap = min(ay2,by2)-max(ay1,by1); // 2 - 0
        
        if(xOverlap>0 && yOverlap>0){
            overlap=xOverlap*yOverlap;
        }
        

        return bArea+aArea-overlap;
    }
};
