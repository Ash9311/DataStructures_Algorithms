//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
//first use a recursive approach and reach bottom of the stack and then
//use sortedInsert function to place the elements at the right place keeping
//other numbers by side and recursion will do the sort
void sortedInsert(stack<int> &stack,int temp){
    if(stack.empty() or temp>stack.top()){
        stack.push(temp);
        return;
    }
    int num = stack.top();
    stack.pop();
    sortedInsert(stack,temp);
    stack.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
        return;
    }
    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack,temp); //while backtracking place element at correct sorted position
}
