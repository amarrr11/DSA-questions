/*543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 */

 #include <iostream>
 using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 class Solution {
 public:
     int solve(TreeNode* root, int &diameter) {
         if (!root) return 0;
         
         int left = solve(root->left, diameter);
         int right = solve(root->right, diameter);
         
         diameter = max(diameter, left + right);
         
         return 1 + max(left, right);
     }
 
     int diameterOfBinaryTree(TreeNode* root) {
         int diameter = 0;
         solve(root, diameter);
         return diameter;
     }
 };
 
 int main() {
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(2);
     root->right = new TreeNode(3);
     root->left->left = new TreeNode(4);
     root->left->right = new TreeNode(5);
 
     Solution sol;
     cout << "Diameter of the binary tree: " << sol.diameterOfBinaryTree(root) << endl;
 
     return 0;
 }
 