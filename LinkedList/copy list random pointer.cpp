/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//create new node . add its head and itself to the map. recursively find next,random w.r.t the original
class Solution {

private:
unordered_map<Node*,Node*> mp;

public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        if(mp.count(head)){ //if head already present then return it
            return mp[head];
        }

        Node* newNode = new Node(head->val);
        mp[head]  = newNode;
        newNode->next = copyRandomList(head->next); //recursively find next,random w.r.t the original
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};
