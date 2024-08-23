/*23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it. 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
*/
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
                tail->next = nullptr;
            } else {
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
                tail->next = nullptr;
            }
        }
        if (head1) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0) return nullptr;
        
        ListNode *head = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            head = merge(head, arr[i]);
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked lists for testing
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    // Add them to a vector
    vector<ListNode*> lists = {l1, l2, l3};

    // Create an instance of the Solution class
    Solution solution;
    
    // Merge the k sorted linked lists
    ListNode* result = solution.mergeKLists(lists);
    
    // Print the merged linked list
    printList(result);

    return 0;
}
