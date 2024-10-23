/*2641. Cousins in Binary Tree II

Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        vector<int> v;
        while(!q.empty()){
            int sum=0;
            int size=q.size();
            while(size--){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;    
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            v.push_back(sum);
        }
        q.push(root);
        root->val=0;
        int lvl=1;
        while(!q.empty() and lvl<v.size()){
            int size=q.size(); 
            
            while(size--){
                int sum=0; 
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    sum=sum+(temp->left->val);
                    q.push(temp->left);
                }
                if(temp->right){
                    sum=sum+(temp->right->val);
                    q.push(temp->right);
                }
                if(sum==v[lvl]){
                    if(temp->left){
                        temp->left->val=0;
                    }
                    if(temp->right){
                        temp->right->val=0;
                    }
                } else {
                    if(temp->left){
                        temp->left->val=(v[lvl]-sum);
                    }
                    if(temp->right){
                        temp->right->val=(v[lvl]-sum);
                    }
                }
            }
            lvl++;
        }
        return root;
    }
};

// Helper function to print the tree in level order
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    //         4
    //       /   \
    //      1     3
    //     / \   / \
    //    2   5 6   7
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    TreeNode* modifiedTree = solution.replaceValueInTree(root);

    // Printing the modified tree
    cout << "Modified tree values in level order: ";
    printTree(modifiedTree);

    // Memory cleanup (optional)
    // Ideally, you would implement a function to delete the tree

    return 0;
}
