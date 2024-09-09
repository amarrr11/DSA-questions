/*725. Split Linked List in Parts

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may 
lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater
than or equal to parts occurring later.

Return an array of the k parts.

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the 
later parts.*/
#include <bits/stdc++.h>
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*>(k, nullptr);
         
        int size = 0;
        ListNode *temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        
        temp = head;
        int persize = size / k;
        int extra = size % k;
        vector<ListNode*> ans(k);
        int i = 0;
        while (k-- && temp) {
            ans[i++] = temp;
            ListNode* prev = NULL;
            int ps = persize;
            if (extra) {
                ps += 1;
                extra--;
            }
            
            while (temp && ps--) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 10; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }
    
    int k = 3;
    Solution solution;
    vector<ListNode*> parts = solution.splitListToParts(head, k);

    // Print the resulting parts
    for (int i = 0; i < k; ++i) {
        cout << "Part " << i+1 << ": ";
        printList(parts[i]);
    }

    return 0;
}
