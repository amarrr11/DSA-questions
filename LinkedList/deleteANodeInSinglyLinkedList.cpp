/*Delete a Node in Single Linked List

Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:

Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. 
Example 2:

Input: 1 -> 5 -> 2 -> 9 
x = 2
Output: 1 -> 2 -> 9
Explanation: 
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.
Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the 
linked list and an integer x. The function returns the head of the modified linked list.*/

#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* deleteNode(Node *Head, int x)
{
    if(x == 1){
        Node* temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    } else {
        x--;
        Node* curr = Head;
        Node* prev = NULL;
        while(x--){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return Head;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original List: ";
    printList(head);
    
    // Deleting the node at position 3
    int position = 3;
    head = deleteNode(head, position);
    
    cout << "List after deleting node at position " << position << ": ";
    printList(head);
    
    // Free remaining nodes
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
