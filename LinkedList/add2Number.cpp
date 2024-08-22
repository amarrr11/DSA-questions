/*2. Add Two Numbers //gfg

Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 283K+Points: 4
Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list that 
represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these
two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked 
list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 45 (4->5->null), num2 = 345 (3->4->5->null)
Output:  3->9->0->null  
 
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Input: num1 = 0063 (0->0->6->3->null), num2 = 07 (0->7->null)
Output: 7->0->null
 
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse the linked list.
    Node* reverse(Node *curr, Node *prev) {
        if (curr == NULL) {
            return prev;
        }
        Node* front = curr->next;
        curr->next = prev;
        return reverse(front, curr);
    }

    // Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
        num1 = reverse(num1, NULL);
        num2 = reverse(num2, NULL);
        
        Node *curr1 = num1, *curr2 = num2;
        Node *head = new Node(0);
        Node *tail = head;
        int carry = 0;

        while (curr1 && curr2) {
            int sum = (curr1->data + curr2->data + carry);
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            carry = sum / 10;
        }

        while (curr1) {
            int sum = (curr1->data + carry);
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
            carry = sum / 10;
        }

        while (curr2) {
            int sum = (curr2->data + carry);
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
            carry = sum / 10;
        }

        if (carry) {
            tail->next = new Node(carry);
        }

        head = reverse(head->next, NULL);
        return head;
    }
};

// Utility function to print a linked list.
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array.
Node* createList(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};  // Represents number 342
    int arr2[] = {5, 6, 4};  // Represents number 465

    Node* num1 = createList(arr1, 3);
    Node* num2 = createList(arr2, 3);

    Solution solution;
    Node* result = solution.addTwoLists(num1, num2);

    cout << "Resultant list: ";
    printList(result);  // Output should be 8 -> 0 -> 7 which represents 807

    return 0;
}
