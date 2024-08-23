/*Flattening a Linked List

Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function
in the driver code for more clarity.

Examples:

Input:

Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *bottom;

    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};

class Solution {
public:
    Node *merge(Node *head1, Node *head2) {
        Node *head = new Node(0);
        Node *tail = head;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->bottom = head1;
                head1 = head1->bottom;
            } else {
                tail->bottom = head2;
                head2 = head2->bottom;
            }
            tail = tail->bottom;
        }
        if (head1) {
            tail->bottom = head1;
        } else {
            tail->bottom = head2;
        }

        return head->bottom;
    }

    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) return root;

        while (root->next) {
            Node *head1 = root;
            Node *head2 = root->next;
            Node *head3 = root->next->next;

            head1->next = NULL;
            head2->next = NULL;

            root = merge(head1, head2);
            root->next = head3;
        }
        return root;
    }
};

void printFlattenedList(Node *root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

int main() {
    // Creating the linked list
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next = new Node(10);
    root->next->bottom = new Node(20);

    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution sol;
    Node *flattenedList = sol.flatten(root);

    // Print the flattened linked list
    printFlattenedList(flattenedList);

    return 0;
}
