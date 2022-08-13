//https://practice.geeksforgeeks.org/problems/queue-reversal/1

//first insert all elements on queue from front to the stack and then insert back to the queue using stack pop
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}


//using recursion
//store the front value and use recursion to go upto last element. and then push back what was stored in 'front' therby we get in reverse
void helper(queue<int> &q){
    if(q.empty()){
       return ;
    }
    int front = q.front();
    q.pop();
    helper(q);
    q.push(front);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    queue<int> res;
    helper(q);
    return q;
}
