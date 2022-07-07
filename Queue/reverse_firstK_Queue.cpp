//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

//first store k elements in the stack and then push the reversed to the queue which will be at the end and the push those first n-k elements to the end of queue

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
  //1 2 3 4 5    k
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
