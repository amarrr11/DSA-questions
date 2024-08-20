/*Intersection Point in Y Shaped Linked Lists

Given two singly linked lists, return the point where two linked lists intersect.

Note: If the linked lists do not merge at any point, return -1.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    // Function to find intersection point in Y-shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        int cnt1 = 0, cnt2 = 0;
        Node *curr1 = head1, *curr2 = head2;
        
        while (curr1) {
            cnt1++;
            curr1 = curr1->next;
        }
        while (curr2) {
            cnt2++;
            curr2 = curr2->next;
        }
        curr1 = head1, curr2 = head2;
        while (cnt1 > cnt2) {
            curr1 = curr1->next;
            cnt1--;
        }
        while (cnt2 > cnt1) {
            curr2 = curr2->next;
            cnt2--;
        }
        
        while (curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
            if (curr1 == curr2) {
                return curr1->data;
            }
        }
        return -1;
    }
}; 
//can also be done by making a loop and getting the starting of the loop

/* Node *slow=head1,*fast=head2;
        
        while(slow->next!=NULL){
            slow=slow->next;
        }
        
        slow->next=head1;
        slow=head2;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
         if (fast == nullptr || fast->next == nullptr) {
            return -1;
        }
        
        slow = head2;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow->data;
      */


Node* addNode(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
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
    // Creating two linked lists with a Y-shaped intersection
    Node* head1 = new Node(1);
    head1 = addNode(head1, 2);
    head1 = addNode(head1, 3);
    head1 = addNode(head1, 4);
    head1 = addNode(head1, 5);

    Node* head2 = new Node(6);
    head2 = addNode(head2, 7);
    
    // Creating intersection at node 4
    head2->next->next = head1->next->next->next;

    Solution sol;
    int intersectionPoint = sol.intersectPoint(head1, head2);
    
    if (intersectionPoint != -1) {
        cout << "Intersection point data: " << intersectionPoint << endl;
    } else {
        cout << "No intersection point found." << endl;
    }
    
    return 0;
}
