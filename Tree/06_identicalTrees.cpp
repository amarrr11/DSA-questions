/*Identical Trees
Difficulty: Easy
Given two binary trees, the task is to find if both of them are identical or not.*/

#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;
    
    // Constructor to create a new node
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Class containing the isIdentical function
class BinaryTree {
public:
    // Function to check if two trees are identical
    bool isIdentical(Node *r1, Node *r2) {
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if (!r1 && r2) return false;
        if (r1 && !r2) return false;
        if (r1->data != r2->data) return false;
        
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};

// Function to print in-order traversal (for testing)
void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    // Creating first tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Creating second tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    BinaryTree tree;
    
    // Check if trees are identical
    if (tree.isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    // Clean up memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
