/*Is Binary Tree Heap
Difficulty: Medium
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
*/

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

class Solution {
  public:
    int total_nodes(Node* node) {
        if (!node) {
            return 0;
        }
        return 1 + total_nodes(node->left) + total_nodes(node->right);
    }
    
    bool BST(Node* root, int index, int count) {
        if (!root) {
            return 1;
        }
        if (index >= count) {
            return 0;
        }
        int a = BST(root->left, 2 * index + 1, count);
        int b = BST(root->right, 2 * index + 2, count);
        return (a && b);
    }
    
    bool heap(Node* root) {
        if (root->left) {
            if (root->left->data > root->data) {
                return 0;
            }
            if (!heap(root->left)) {
                return 0;
            }
        }
        if (root->right) {
            if (root->right->data > root->data) {
                return 0;
            }
            return heap(root->right);
        }
        return 1;
    }
    
    bool isHeap(Node* tree) {
        int num = total_nodes(tree);
        if (!BST(tree, 0, num)) {
            return 0;
        }
        return heap(tree);
    }
};

int main() {
    Solution solution;

    // Creating a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    
    // Check if the binary tree is a heap
    if (solution.isHeap(root)) {
        cout << "The binary tree is a heap" << endl;
    } else {
        cout << "The binary tree is not a heap" << endl;
    }

    return 0;
}
