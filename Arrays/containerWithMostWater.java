//https://leetcode.com/problems/container-with-most-water/
//use 2 pointer approach and find the max water container after iterating all, can calculate the content by multiplying difference of
//2 references and height of min height

class Solution {
    public int maxArea(int[] height) {
        int water=0;
        int i=0;
        int j = height.length-1;
        
        while(i<j){
            water = Math.max(water ,(j-i)*Math.min(height[i],height[j]));
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return water;
        
    }
}
