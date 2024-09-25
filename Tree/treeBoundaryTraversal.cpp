/*Tree Boundary Traversal
Difficulty: Medium
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always
 travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node 
you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it 
was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:


 

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
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
    // Function to find the left boundary (excluding leaf nodes)
    void findLeft(Node* root, vector<int>& ans) {
        // If the current node is NULL or a leaf node, return
        if (!root || (!root->left && !root->right)) return;
        
        // Add the current node's data to the answer
        ans.push_back(root->data);
        
        // Recur for the left child if it exists, else for the right child
        if (root->left) findLeft(root->left, ans);
        else findLeft(root->right, ans);
    }
    
    // Function to find all leaf nodes in the tree
    void findleaf(Node* root, vector<int>& ans) {
        // Base case: If the node is NULL, return
        if (!root) return;
        
        // If the current node is a leaf, add it to the answer
        if (!root->left && !root->right) {
            ans.push_back(root->data);
        }
        
        // Recur for the left and right subtrees
        findleaf(root->left, ans);
        findleaf(root->right, ans);
    }
    
    // Function to find the right boundary (excluding leaf nodes)
    void findright(Node* root, vector<int>& ans) {
        // If the current node is NULL or a leaf node, return
        if (!root || (!root->left && !root->right)) return;
        
        // Recur for the right child if it exists, else for the left child
        if (root->right) findright(root->right, ans);
        else findright(root->left, ans);
        
        // Add the current node's data to the answer after recursion
        ans.push_back(root->data);
    }
    
    // Function to get the boundary traversal of the binary tree
    vector<int> boundary(Node* root) {
        vector<int> ans;
        
        // If the root is NULL, return an empty result
        if (!root) return {};
        
        // If the root is the only node (leaf node), return its data
        if (!root->left && !root->right) return {root->data};
        
        // Add the root's data to the answer
        ans.push_back(root->data);
        
        // Find the left boundary (excluding leaf nodes)
        findLeft(root->left, ans);
        
        // Find all leaf nodes
        findleaf(root, ans);
        
        // Find the right boundary (excluding leaf nodes) and add in reverse order
        findright(root->right, ans);
        
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->right->right = new Node(10);

    // Creating an object of Solution class
    Solution sol;
    
    // Finding the boundary of the binary tree
    vector<int> boundary = sol.boundary(root);
    
    // Printing the boundary traversal
    for (int val : boundary) {
        cout << val << " ";
    }

    return 0;
}
