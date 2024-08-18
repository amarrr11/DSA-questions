/*328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]*/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* evenpos = odd->next;

        while (odd->next != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenpos;
        return head;
    }
};

//using array:
/*      vector<int> arr;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i+=2){
            ans.push_back(arr[i]);
        }
        for(int i=1;i<arr.size();i+=2){
            ans.push_back(arr[i]);
        }
        curr=head;
        int i=0;
        while(curr){
            curr->val=ans[i++];
            curr=curr->next;
        }
        return head;
        
    */

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* result = solution.oddEvenList(head);

    // Print the result
    printList(result);

    return 0;
}
