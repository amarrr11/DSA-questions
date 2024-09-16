/*Level order traversal in spiral form
Difficulty: Easy
Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right
to left and for all the odd levels we print the node's value from left to right. */


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> findSpiral(Node* root) {
    if (root == nullptr) return {}; // Handle empty tree

    stack<Node*> s1; // Stack for current level (right to left)
    stack<Node*> s2; // Stack for next level (left to right)
    s1.push(root);
    vector<int> ans;

    while (!s1.empty() || !s2.empty()) {
        // Process nodes in s1 (right to left)
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);

            // Push right first for the next level (left to right)
            if (temp->right) {
                s2.push(temp->right);
            }
            if (temp->left) {
                s2.push(temp->left);
            }
        }

        // Process nodes in s2 (left to right)
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);

            // Push left first for the next level (right to left)
            if (temp->left) {
                s1.push(temp->left);
            }
            if (temp->right) {
                s1.push(temp->right);
            }
        }
    }

    return ans;
}

int main() {
    // Creating a sample binary tree:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call the findSpiral function
    vector<int> result = findSpiral(root);

    // Print the result
    cout << "Spiral order traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
