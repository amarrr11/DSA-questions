/* 1123. Lowest Common Ancestor of Deepest Leaves

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth = 0;
    unordered_map<int, int> mp;

    void depth(TreeNode* root, int d) {
        if (!root) return;

        if (d > maxDepth) maxDepth = d;
        mp[root->val] = d;

        if (root->left) depth(root->left, d + 1);
        if (root->right) depth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (!root || mp[root->val] == maxDepth) return root;

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if (left && right) return root;
        if (left) return left;
        return right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};

int main() {
    /*
        Example tree:
                1
               / \
              2   3
             /
            4
    */
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    TreeNode* lca = sol.lcaDeepestLeaves(root);

    if (lca)
        cout << "LCA of deepest leaves: " << lca->val << endl;
    else
        cout << "No LCA found." << endl;

    // Cleanup
    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}
