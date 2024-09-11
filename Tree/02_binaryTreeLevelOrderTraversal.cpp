/*102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by
 level).*/

#include <bits/stdc++.h>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (1) {
            int size = q.size();
            if (size == 0) break;
            vector<int> data;

            while (size > 0) {
                TreeNode* temp = q.front();
                q.pop();
                data.push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                size--;
            }

            ans.push_back(data);
        }
        return ans;
    }
};

int main() {
    // Creating the binary tree:
    //         3
    //        / \
    //       9  20
    //         /  \
    //        15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Printing the level order traversal
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Cleaning up the dynamically allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
