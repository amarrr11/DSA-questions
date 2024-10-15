/*Lowest Common Ancestor in a BST
Difficulty: Easy
Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2). Find the Lowest Common 
Ancestors of the two nodes in the BST.

Example 1:

Input:
              5
            /   \
          4      6
         /        \
        3          7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2*/

#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find the Lowest Common Ancestor (LCA) in a BST
Node* LCA(Node* root, int n1, int n2) {
    if ((n1 > root->data && n2 < root->data) || (n1 < root->data && n2 > root->data)) {
        return root;
    }
    while (root != NULL) {
        if (n1 > root->data && n2 > root->data) {
            root = root->right;
        }
        else if (n1 < root->data && n2 < root->data) {
            root = root->left;
        } else {
            return root;
        }
    }
    return NULL;
}
/*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val>p->val and root->val<q->val) or (root->val<p->val and root->val>q->val)){
            return root;
        }
        if(p->val>root->val and q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val<root->val and q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }*/

// Function to insert a node in the BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to build a simple BST for testing
Node* buildSampleBST() {
    Node* root = new Node(20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    return root;
}

// Main function to test the LCA function
int main() {
    Node* root = buildSampleBST();

    int n1 = 10, n2 = 14;
    Node* lca = LCA(root, n1, n2);
    if (lca != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    n1 = 14, n2 = 8
