/*Mirror Tree
Difficulty: Easy
Given a Binary Tree, convert it into its mirror.*/

#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;
    
    // Constructor to create a new node
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Class containing the mirror function
class Solution {
public:
    // Function to convert a binary tree into its mirror tree
    void mirror(Node* node) {
        if (node == NULL) return;
        
        // Swap the left and right children
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        // Recursively mirror the left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Function to print in-order traversal
void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Solution sol;

    // Print in-order traversal of original tree
    cout << "Original tree (in-order): ";
    inOrder(root);
    cout << endl;
    
    // Mirror the binary tree
    sol.mirror(root);

    // Print in-order traversal of mirrored tree
    cout << "Mirrored tree (in-order): ";
    inOrder(root);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
