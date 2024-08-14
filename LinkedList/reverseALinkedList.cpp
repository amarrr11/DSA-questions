/*206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

Input: head = [1,2]
Output: [2,1]
*/

#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        /*vector<int> ans;
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=ans.size()-1;
        while(temp){
            temp->val=ans[i--];
            temp=temp->next;
        }
        return head;*/

        //if we want to change the address too.

        ListNode *curr = head, *prev = NULL, *fut = NULL;
        while (curr) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev; //cause prev is at last index
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    // Print the reversed linked list
    ListNode* temp = reversedHead;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }

    // Clean up the memory
    temp = reversedHead;
    while (temp) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
