/*Check for BST
Difficulty: Easy
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 
Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
Input:
   10
 /    \
5      20
      /   \
     9     25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


void inorder(Node* root, vector<int> &ans) {
    if (!root) return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// Function to check if the binary tree is a BST
bool isBST(Node* root) {
    vector<int> ans;
    inorder(root, ans);
    
    // Check if the inorder traversal results in a sorted list
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] <= ans[i - 1]) return false;
    }
    return true;
}

/*bool solve(Node *root,int &prev)
    {
        if(!root) return 1;
        
        bool l=solve(root->left,prev);
        if(l==0) return 0;
        
        if(root->data<=prev) return 0;
        
        prev=root->data;
        
        return solve(root->right,prev);
    }
    
    bool isBST(Node* root) {
        
        int prev=INT_MIN;
        return solve(root,prev);
        
    }
        */

int main() {
    // Creating a binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    
    // Check if the binary tree is a BST
    if (isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
}
