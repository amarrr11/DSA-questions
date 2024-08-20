/*141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following 
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note 
that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // // your code here
        // if(head==NULL or head->next==NULL) return false;
        // unordered_map<Node*,int> mp;
        // Node* curr=head;
        // while(curr){
        //     if(mp[curr]){
        //         return true;
        //     }
        //     mp[curr]++;
        //     curr=curr->next;
        // }
        // return false;
        
        if(head==NULL or head->next==NULL) return false;
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create a linked list with a loop for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; // Creating a loop
    
    Solution sol;
    if (sol.detectLoop(head))
        cout << "Loop detected in the linked list." << endl;
    else
        cout << "No loop in the linked list." << endl;

    return 0;
}
