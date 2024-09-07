/*24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the 
values in the list's nodes (i.e., only nodes themselves may be changed.)


Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;

        while(dummy->next and dummy->next->next){
            ListNode *curr=dummy->next;
            ListNode *curr2=dummy->next->next;
            curr->next=curr2->next;
            curr2->next=curr;
            dummy->next=curr2;
            dummy=curr;
        }
        return temp->next;

        // ListNode *curr=head;
        // vector<int> arr;
        // while(curr){
        //     arr.push_back(curr->val);
        //     curr=curr->next;
        // }
        // curr=head;
        // for(int i=0;i<arr.size()-1;i+=2){
        //     swap(arr[i],arr[i+1]);
        // }
        // int i=0;
        // while(curr){
        //     curr->val=arr[i++];
        //     curr=curr->next;
        // }
        // return head;
    }
};

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.swapPairs(head);

    // Printing the swapped linked list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
