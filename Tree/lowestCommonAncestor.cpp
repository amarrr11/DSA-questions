/*236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
 lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1*/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) {
            return root;
        }

        return left ? left : right; // Return the non-null node if one is found
    }
};

int main() {
    // Create a sample binary tree:
    //          3
    //        /   \
    //       5     1
    //      / \   / \
    //     6   2 0   8
    //        / \
    //       7   4

    TreeNode* root = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);

    root->left = node5;
    root->right = node1;
    node5->left = node6;
    node5->right = node2;
    node1->left = node0;
    node1->right = node8;
    node2->left = node7;
    node2->right = node4;

    Solution solution;

    // Find LCA of nodes 5 and 1
    TreeNode* lca1 = solution.lowestCommonAncestor(root, node5, node1);
    cout << "LCA of 5 and 1: " << (lca1 ? lca1->val : -1) << endl; // Expected output: 3

    // Find LCA of nodes 5 and 4
    TreeNode* lca2 = solution.lowestCommonAncestor(root, node5, node4);
    cout << "LCA of 5 and 4: " << (lca2 ? lca2->val : -1) << endl; // Expected output: 5

    // Find LCA of nodes 7 and 4
    TreeNode* lca3 = solution.lowestCommonAncestor(root, node7, node4);
    cout << "LCA of 7 and 4: " << (lca3 ? lca3->val : -1) << endl; // Expected output: 2

    // Clean up memory (optional)
    delete root;
    delete node5;
    delete node1;
    delete node6;
    delete node2;
    delete node0;
    delete node8;
    delete node7;
    delete node4;

    return 0;
}
