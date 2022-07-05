#include <iostream>
#include<queue>
using namespace std;
 
// Data structure to represent a special linked list node with
// an additional `down` pointer
struct Node
{
    int data;
    Node* next;
    Node* down;
 
    Node(int data)
    {
        this->data = data;
        this->next = this->down = nullptr;
    }
};
 
// Utility function to print a list with `down` and `next` pointers
void printOriginalList(Node* head)
{
    if (head == nullptr) {
        return;
    }
 
    cout << ' ' << head->data << ' ';
 
    if (head->down)
    {
        cout << "[";
        printOriginalList(head->down);
        cout << "]";
    }
 
    printOriginalList(head->next);
}
 
// Utility function to print a linked list
void printFlatenedList(Node* head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
 
    cout << "null" << '\n';
}
 
// traverse through the linked list, whenever we find a down node, insert it into the queue and if the next pointer is null
//pop the front node of the queue and make it as the next pointer and thus we get flattened linked list
Node* flattenList(Node* head)
{
    Node *curr = head;
    queue<Node*> q;
    
    while(curr!=NULL){
        if(curr->down){
            q.push(curr->down);
        }
        if(curr->next==NULL){
            curr->next = q.front();
            q.pop();
        }
        curr = curr->next;
    }
    return head;
}
 
int main()
{
    // create individual nodes and link them together later
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* seven = new Node(7);
    Node* eight = new Node(8);
    Node* nine = new Node(9);
    Node* ten = new Node(10);
    Node* eleven = new Node(11);
    Node* twelve = new Node(12);
    Node* thirteen = new Node(13);
    Node* fourteen = new Node(14);
    Node* fifteen = new Node(15);
 
    // set head node
    Node* head = one;
 
    // set next pointers
    one->next = four;
    four->next = fourteen;
    fourteen->next = fifteen;
    five->next = nine;
    nine->next = ten;
    seven->next = eight;
    eleven->next = thirteen;
 
    // set down pointers
    one->down = two;
    two->down = three;
    four->down = five;
    five->down = six;
    six->down = seven;
    ten->down = eleven;
    eleven->down = twelve;
 
    cout << "The original list is :" << '\n';
    printOriginalList(head);
 
    head = flattenList(head);
    cout << "\n\nThe flattened list is :" << '\n';
    printFlatenedList(head);
 
    return 0;
}
