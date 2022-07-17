/**
 //https://leetcode.com/problems/swap-nodes-in-pairs/
 //https://leetcode.com/problems/swap-nodes-in-pairs/discuss/1775033/SWAPPING-NODES-(Not-just-the-values)-oror-Visual-Explanation-oror-Well-Explained-oror-C%2B%2B
 
 * Definition for singly-linked list. 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//create a new Node i.e dummyNode place it before the curr node and then perform reversing
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head or !head->next){
            return head;
        }
        
        ListNode *dummyNode = new ListNode();
        ListNode *prevNode = dummyNode;
        ListNode *currNode = head;
        //1 2 3 4           input        //dummyNode 1 2 3 4
        //2 1 4 3           output
        while(currNode and currNode->next){
            prevNode->next = currNode->next;//we want the node with value 2 after the dummyNode.
            currNode->next = prevNode->next->next; //next pointer of node with value 1 should point to whatever the node with value 2 is pointing to originally
            prevNode->next->next = currNode; //node with value 2 should point to node with value 1
            //dummy(prev) 2 1(curr) 3 4 NULL
            
            //Now for the next iteration, we have to swap nodes with values 3 and 4. For that the prevNode should point to node with value 1 and the currNode should                point to node with value 3
            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummyNode->next; //since our head got misplaced 
    }
};
