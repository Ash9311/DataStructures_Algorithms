//https://practice.geeksforgeeks.org/problems/burning-tree/1
//create nodeToparent mapping,find target node,burn the tree in min time
class Solution {
    
    private:
    Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent){
        Node* targetNode = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL; //since parent of root is null
        while(!q.empty()){ //make a level order traversal and create parent mapping, find target node
            Node* front = q.front();
            q.pop();
            
            if(front->data==target){ //target check
                targetNode = front;
            }
            if(front->left){  //adding left node to queue and creating parent mapping
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }
    
    private:
    int burnTree(Node* root,map<Node*,Node*> &nodeToParent){ //root is target node initially
        map<Node*,bool> visited; // visited map is needed to keep track of nodes while traversing
        int timeTaken=0;
        queue<Node*> q;
        q.push(root); //target node is in queue initially now the burning starts
        
        while(!q.empty()){
            bool isAdditionDone = false;//need to maitain this in order to track time taken
            int size = q.size(); //need to take size in order to process nodes neighbours only
            for(int i=0;i<size;i++){
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                //left,right and parent are the possible neighbours. make sure u mark nodes visited once visited
                if(front->left and !visited[front->left]){ //left neighbour check
                    visited[front->left]= true;
                    isAdditionDone = true;
                    q.push(front->left);
                }
                if(front->right and !visited[front->right]){ //right neighbour check
                    visited[front->right]= true;
                     isAdditionDone = true;
                    q.push(front->right);
                }
                if(nodeToParent[front] and !visited[nodeToParent[front]]){ //parent neighbour check
                    visited[nodeToParent[front]] = true;
                     isAdditionDone = true;
                    q.push(nodeToParent[front]);
                }
            }
            if( isAdditionDone == true){ //3 nodes can also be burnt in 1 second, counted as 1 second
                timeTaken++;
            }
        }
        return timeTaken;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> nodeToParent; //so that we get to know each node's parent
        Node *targetNode = createParentMapping(root,target,nodeToParent); //creates parent node mapping and finds targetNode
        return burnTree(targetNode,nodeToParent);
    }
};
