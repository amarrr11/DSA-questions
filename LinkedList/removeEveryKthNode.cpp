/*Remove every kth node
Difficulty: EasyAccuracy: 29.88%Submissions: 87K+Points: 2
Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

Example 1:

Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2
Output: 
1 -> 3 -> 5 -> 7
Explanation: 
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* deleteK(Node *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        if (k == 1) {
            return NULL;
        }
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while (curr) {
            if (count % k == 0) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
            count++;
        }
        return head;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list with nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    int k = 2; // Set k to delete every k-th node

    Solution ob;
    head = ob.deleteK(head, k);
    
    // Print the modified linked list
    printList(head);
    
    return 0;
}
