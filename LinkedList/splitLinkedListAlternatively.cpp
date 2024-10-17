/*Split Linked List Alternatingly
Difficulty: EasyAccuracy: 42.46%Submissions: 13K+Points: 2
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given 
linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    vector<Node*> alternatingSplitList(Node* head) {
        vector<Node*> ans;
        if (head == nullptr) {
            return {nullptr, nullptr};
        }
        if (head->next == nullptr) {
            return {head, nullptr}; // Handle single node case
        }
        
        Node* h1 = head;
        Node* h11 = h1;
        Node* h2 = head->next;
        Node* h22 = h2;
        
        while (h22 != nullptr && h22->next != nullptr) {
            h11->next = h22->next;
            h11 = h11->next;
            
            h22->next = h11->next;
            h22 = h22->next;
        }
        
        if (h22) { // If h22 is not null, set next to null
            h11->next = nullptr;
        }
        
        if (h22 && h22->next) {
            h22->next = nullptr;
        }
        
        ans.push_back(h1);
        ans.push_back(h2);
        return ans;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution solution;
    vector<Node*> result = solution.alternatingSplitList(head);
    
    // Print the first list
    cout << "First List: ";
    Node* list1 = result[0];
    while (list1 != nullptr) {
        cout << list1->data << " ";
        list1 = list1->next;
    }
    cout << endl;

    // Print the second list
    cout << "Second List: ";
    Node* list2 = result[1];
    while (list2 != nullptr) {
        cout << list2->data << " ";
        list2 = list2->next;
    }
    cout << endl;

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
