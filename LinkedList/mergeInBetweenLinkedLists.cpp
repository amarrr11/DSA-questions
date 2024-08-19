/*1669. Merge In Between Linked Lists

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above 
figure indicate the result.*/

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
    ListNode* mergeInBetween(ListNode* head1, int a, int b, ListNode* head2) {
        ListNode* curr = head1;
        for(int i = 1; i < a; i++) {
            curr = curr->next;
        }
        
        ListNode* tail = curr;

        for(int i = a; i <= b; i++) {
            tail = tail->next;
        }

        curr->next = head2;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = tail->next;
        return head1;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to create a new ListNode
ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    // Creating first linked list: 0 -> 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = createNode(0);
    head1->next = createNode(1);
    head1->next->next = createNode(2);
    head1->next->next->next = createNode(3);
    head1->next->next->next->next = createNode(4);
    head1->next->next->next->next->next = createNode(5);

    // Creating second linked list: 1000000 -> 1000001 -> 1000002
    ListNode* head2 = createNode(1000000);
    head2->next = createNode(1000001);
    head2->next->next = createNode(1000002);

    Solution solution;
    int a = 3, b = 4;

    cout << "List 1 before merge: ";
    printList(head1);

    cout << "List 2 before merge: ";
    printList(head2);

    ListNode* mergedHead = solution.mergeInBetween(head1, a, b, head2);

    cout << "List after merge: ";
    printList(mergedHead);

    return 0;
}
