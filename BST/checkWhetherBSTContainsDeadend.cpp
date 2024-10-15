/*
Check whether BST contains Dead End
Difficulty: MediumAccuracy: 35.99%Submissions: 80K+Points: 4
Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means a leaf node, at which no other node can be inserted.

Example 1:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : 
Yes
Explanation : 
Node 1 is a Dead End in the given BST.
Example 2:

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : 
Yes
Explanation : 
Node 9 is a Dead End in the given BST.

*/

#include <bits/stdc++.h>
using namespace std;

// Definition of the Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Helper function to check if there is a dead end in the tree
    bool find(Node* root, int lower, int upper) {
        // Base condition to check if the current node forms a dead end
        if (root->data - lower <= 1 && upper - root->data <= 1) {
            return 1; // Dead end found
        }

        // Check in the left subtree
        if (root->left) {
            // Recursively search in the left subtree with updated boundaries
            if (find(root->left, lower, root->data)) {
                return 1; // Dead end found in the left subtree
            }
        }

        // Check in the right subtree
        if (root->right) {
            // Recursively search in the right subtree with updated boundaries
            if (find(root->right, root->data, upper)) {
                return 1; // Dead end found in the right subtree
            }
        }

        // No dead end found
        return 0;
    }

    // Function to determine if there is a dead end in the binary tree
    bool isDeadEnd(Node* root) {
        if (!root) return 0; // If the tree is empty, no dead end
        return find(root, 1, INT_MAX); // Start searching with the range [1, INT_MAX]
    }
};

// Function to insert a node into the binary tree
Node* insert(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    // Creating a binary search tree
    Node* root = nullptr;
    Solution sol;

    // Inserting nodes into the binary search tree
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);

    // Checking if there is a dead end in the tree
    if (sol.isDeadEnd(root)) {
        cout << "The tree contains a dead end." << endl;
    } else {
        cout << "The tree does not contain a dead end." << endl;
    }

    return 0;
}
