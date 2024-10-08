/*Delete a node from BST
Difficulty: MediumAccuracy: 40.7%Submissions: 122K+Points: 4
Given a Binary Search Tree and a node value x. Delete the node with the given value x from the BST. If no node with value 
x exists, then do not make any change. Return the root of the BST after deleting the node with value x. Do not make any 
update if there's no node with value x present in the BST.

Note: The generated output will be the inorder traversal of the modified tree.

Examples :

Input:
      2
    /   \
   1     3
x = 12
Output: 1 2 3
Explanation: In the given input there is no node with value 12 , so the tree will remain same.
Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
x = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12 */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* deleteNode(Node* root, int x) {
    if (!root) return nullptr;
    
    if (root->data > x) {
        root->left = deleteNode(root->left, x);
    } else if (root->data < x) {
        root->right = deleteNode(root->right, x);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* parent = root;
            Node* child = root->left;
            
            while (child->right) {
                parent = child;
                child = child->right;
            }
            
            if (parent != root) {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            } else {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;
    
    int key = 50;
    root = deleteNode(root, key);
    
    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
