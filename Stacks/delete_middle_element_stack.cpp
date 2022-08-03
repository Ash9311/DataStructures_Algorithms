//https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=1
//use a recursive approach, pop top elements from stack until count reaches size/2 and then backtrack the other popped elements
void solve(stack<int> &inputStack,int count,int size){
    if(count==size/2){
        inputStack.pop(); //as we have to delete the middle one
        return;
    }
    int temp = inputStack.top();
    inputStack.pop();
    solve(inputStack,count+1,size); //recursive call
    inputStack.push(temp); //backtrack the past popped one when we were hunting middle element
}

void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack,0,N);
}
