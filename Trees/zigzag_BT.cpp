//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//create a queue, push the root to it, and create a variable leftToRight for direction tracking, and then while
//q is not empty process for each levels and store the result
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight = true;
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> temp(size);
    	    
    	    //level process
    	    for(int i=0;i<size;i++){
    	        Node *frontNode = q.front();
    	        q.pop();
    	        //normal insert or reverse insert
    	        int index = leftToRight ? i : size - i - 1; 
    	        temp[index] = frontNode->data; //store it
    	        //check left and right nodes
    	        if(frontNode->left){
    	            q.push(frontNode->left);
    	        }
    	         if(frontNode->right){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    //direction change after level process
    	    leftToRight = !leftToRight;
    	    
    	    //push ans to result
    	    for(auto it: temp){
    	        result.push_back(it);
    	    }
    	}
    	return result;
    }
};
