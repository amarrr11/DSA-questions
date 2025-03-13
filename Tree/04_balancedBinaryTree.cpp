/*110. Balanced Binary Tree
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false*/

#include <iostream>
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
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);

        if(left==-1 or right==-1) return -1;
        if(abs(left-right)>1){
            return -1;
        }
        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        if(height(root)==-1) return false;
        return true; 
    }
};

int main() {
    // Constructing a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    Solution sol;
    cout << (sol.isBalanced(root) ? "The tree is balanced." : "The tree is not balanced.") << endl;

    return 0;
}
