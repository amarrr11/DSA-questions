/*61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]*/

#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0 || head->next == nullptr) return head;

        ListNode* curr = head;
        int cnt = 1;
        while(curr->next != nullptr){
            cnt++;
            curr = curr->next;
        }
        k %= cnt;
        if(k == 0) return head;
        cnt -= k;

        ListNode* prev = nullptr;
        curr = head;
        while(cnt--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;

        ListNode* tail = curr;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = head;
        return curr;


        
        // vector<int> arr;
        // ListNode* temp=head;
        // while(temp){
        //     arr.push_back(temp->val);
        //     temp=temp->next;
        // }
        // k%=arr.size();
        // temp=head;
        // reverse(arr.begin(),arr.end());
        // reverse(arr.begin(),arr.begin()+k);
        // reverse(arr.begin()+k,arr.end());

        // int i=0;
        // while(temp){
        //     temp->val=arr[i++];
        //     temp=temp->next;
        // }
        // return head;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Rotate the list to the right by 2 places
    Solution sol;
    ListNode* rotatedHead = sol.rotateRight(head, 2);

    cout << "Rotated list: ";
    printList(rotatedHead);

    // Clean up memory
    ListNode* temp;
    while (rotatedHead) {
        temp = rotatedHead;
        rotatedHead = rotatedHead->next;
        delete temp;
    }

    return 0;
}
