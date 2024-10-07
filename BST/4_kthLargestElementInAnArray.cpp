/*Kth largest element in BST
Difficulty: Easy
Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing 
any modification in Binary Search Tree.

Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10*/

#include <bits/stdc++.h>
using namespace std;

// Definition for the Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Class Solution as given in the prompt
class Solution {
    public:
    
    void inorder(Node* root, int &k, int &ele) {
        if (!root) return;

        inorder(root->right, k, ele);

        k--;        

        if (k == 0) {
            ele = root->data;
            return;
        }

        inorder(root->left, k, ele);
    }    
    
    int kthLargest(Node *root, int k) {
        int ele = INT_MIN;
        inorder(root, k, ele);
        return ele;
    }
};

// Function to insert nodes in the BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    
    return root;
}

int main() {
    // Example BST
    Node* root = nullptr;
    
    // Inserting nodes in the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    Solution sol;
    
    int k = 3; // Example: Find 3rd largest element
    cout << "The " << k << "rd largest element is " << sol.kthLargest(root, k) << endl;

    return 0;
}
