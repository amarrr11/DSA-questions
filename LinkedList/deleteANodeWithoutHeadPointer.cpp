/*Delete without head pointer

You are given a node del_node of a Singly Linked List where you have to delete a value of the given node from the linked 
list but you are not given the head of the list.

By deleting the node value, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before & after the del_node node should be in the same order.
Note:

Multiple nodes can have the same values as the del_node, but you must only remove the node whose pointer del_node is given to
you.
It is guaranteed that there exists a node with a value equal to the del_node value and it will not be the last node of the 
linked list.

Example 1:

Input:
Linked List = 1 -> 2
del_node = 1
Output: 
2
Explanation: 
After deleting 1 from the linked list, 
we have remaining nodes as 2.
Example 2:

Input:
Linked List = 10 -> 20 -> 4 -> 30
del_node = 20
Output: 
10 4 30
Explanation: 
After deleting 20 from the linked list, 
we have remaining nodes as 10, 4, 30.
Your Task:
You don't need to read or print anything. You only need to complete the function deleteNode() which takes a reference of the
 deleting node value & your task is to delete the given node value.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
} *head;

class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
        if (del_node == NULL || del_node->next == NULL)
            return;
        
        Node* temp = del_node->next;
        del_node->data = temp->data;
        del_node->next = temp->next;
        delete temp;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list 10->20->30->40->50
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    
    cout << "Original Linked List: ";
    printList(head);
    
    // Suppose we want to delete node with value 30
    Node* del_node = head->next->next; // Node with value 30
    
    Solution sol;
    sol.deleteNode(del_node);
    
    cout << "Linked List after deleting node 30: ";
    printList(head);
    
    return 0;
}
