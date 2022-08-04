//https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//recursively keep popping elements until stack is empty, and then insert the element at the
//bottom and then insert other elements via backtracking
void solve(stack<int> &myStack, int x,stack<int> &result){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int temp = myStack.top();
    myStack.pop();
    solve(myStack,x,result);
    myStack.push(temp); //backtrack
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int> result;
    solve(myStack,x,result);
    return myStack;
}
