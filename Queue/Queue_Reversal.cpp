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
