
//https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

//keep top element of the stack aside and leave it to recusion to reverse other elements and int the end insert the top element 
//which was kept aside at the bottom
void insertAtBottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int num = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,temp); 
}

//normal reverse
// void reverseStack(stack<int> &stack) {
//     if(stack.empty()){
//         return;
//     }
//     int temp = stack.top();
//     stack.pop();
//     reverseStack(stack);
//     stack.push(temp); 
// }
