/*Remove loop in Linked List

Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected 
back to a node in the same list.  So if the next of the previous node is null. then there is no loop.  Remove the loop from
the linked list, if it is present (we mainly need to make the next of the last node null). Otherwise, keep the linked list
as it is.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        Node *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (fast == nullptr || fast->next == nullptr) {
            return;
        }
        
        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        while (slow->next != fast) {
            slow = slow->next;
        }
        
        slow->next = nullptr;
    }
};

// Utility function to create a loop for testing.
void createLoop(Node* head, int k) {
    Node* temp = head;
    Node* loopNode = nullptr;
    int count = 1;
    while (temp->next != nullptr) {
        if (count == k) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode != nullptr) {
        temp->next = loopNode;
    }
}

// Utility function to print the linked list.
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    createLoop(head, 3); // Creating a loop at position 3
    
    Solution sol;
    sol.removeLoop(head);
    
    printList(head); // Should print the list without a loop
    
    return 0;
}
