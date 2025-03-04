/*129. Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.*/

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

/* USING BFS 

int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        // dfs(root,0);
        int sum=0;
        queue<TreeNode*> q1;
        queue<int> q2;

        q1.push(root);
        q2.push(root->val);
        while(!q1.empty()){
            TreeNode* r=q1.front();
            int currSum=q2.front();
            q2.pop();
            q1.pop();

            if(!r->left and !r->right){
                sum+=currSum;
            }

            if(r->left){
                q1.push(r->left);
                q2.push(currSum*10+r->left->val);
            }
            if(r->right){
                q1.push(r->right);
                q2.push(currSum*10+r->right->val);
            }
        }
        
        return sum;
    }


*/

class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root, int currSum) {
        if (!root) return;

        currSum = currSum * 10 + root->val;

        dfs(root->left, currSum);
        dfs(root->right, currSum);

        if (!root->left && !root->right) {
            sum += currSum;
            return;
        }
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        dfs(root, 0);
        
        return sum;
    }
};

int main() {
    Solution sol;

    // Example 1:
    // Tree Structure:
    //        1
    //       / \
    //      2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    cout << "Sum of root-to-leaf numbers (Example 1): " << sol.sumNumbers(root1) << endl; // Output: 25 (12 + 13)

    // Reset solution object to clear previous sum
    sol.sum = 0;

    // Example 2:
    // Tree Structure:
    //        4
    //       / \
    //      9   0
    //     / \
    //    5   1
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(0);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(1);

    cout << "Sum of root-to-leaf numbers (Example 2): " << sol.sumNumbers(root2) << endl; // Output: 1026 (495 + 491 + 40)

    // Free allocated memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
