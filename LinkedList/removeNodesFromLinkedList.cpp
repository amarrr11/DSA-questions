/*2487. Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        stack<int> s;
        vector<int> arr;
        
        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(arr[i]);
            } else if (!s.empty() and s.top() <= arr[i]) {
                s.push(arr[i]);
            } else {
                continue;
            }
        }
        
        curr = head;
        while (!s.empty()) {
            curr->val = s.top();
            s.pop();
            if (s.size() == 0) {
                curr->next = NULL;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};

int main() {
    // Create a linked list: 1 -> 3 -> 2 -> 5 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);
    
    // Solution object
    Solution sol;
    ListNode* result = sol.removeNodes(head);
    
    // Print the modified list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    
    // Output should be: 5 4
    return 0;
}
