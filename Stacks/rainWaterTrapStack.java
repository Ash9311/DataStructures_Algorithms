class Solution {
    public int trap(int[] height) {
        Stack<Integer> st = new Stack<>();
        int curr=0,water=0;
        
        while(curr<height.length){
            
            while(!st.isEmpty() &&  height[curr]>height[st.peek()]){
                int top = st.pop();
                if(st.isEmpty()){
                    break;
                }
                int distance = curr - st.peek() -1 ;
                int min_height = Math.min(height[curr],height[st.peek()])-height[top];
                water += distance * min_height;
                
            }
            st.push(curr++);
        }
        return water;
    }
}
