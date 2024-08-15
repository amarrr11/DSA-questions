/*19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]*/

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        
        ListNode* temp = head;
        
        // Calculate the size of the list
        while (temp) {
            size++;
            temp = temp->next;
        }
        
        temp = head;
        ListNode* prev = NULL;
        
        // If we need to remove the head node
        if (n == size) {
            if (head->next == NULL) {
                return NULL;
            } else {
                head = head->next;
                return head;
            }
        }
        
        // Traverse to the node before the one to be removed
        int i = 1;
        while (i != (size - n)) {
            i++;
            prev = temp;
            temp = temp->next;
        }
        
        // Remove the nth node from the end
        prev->next = temp->next;
        delete temp;
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Create a Solution object and test removeNthFromEnd
    Solution sol;
    int n = 2; // Remove 2nd node from end (4 in this case)
    head = sol.removeNthFromEnd(head, n);

    // Print the modified list
    cout << "Modified list after removing " << n << "th node from end: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
