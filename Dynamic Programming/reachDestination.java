//https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111357/offering/1281135?leftPanelTab=0

public class Solution {
	public static boolean reachDestination(int sx, int sy, int dx, int dy) {
		// Write your code here
         if(solve(sx,sy,dx,dy)){
            return true;
        }
        return false;
        
	}
    
    static boolean solve(int sx,int sy,int dx,int dy){
       if(sx==dx && sy==dy){
            return true;
        }
        
        if(sx>dx || sy>dy){
            return false;
        }
        
        if(dx>dy){
            return solve(sx,sy,dx-dy,dy);
        }
        return solve(sx,sy,dx,dy-dx);
        
    }
}
