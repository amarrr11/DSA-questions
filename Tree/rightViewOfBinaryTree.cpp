/*199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
ordered from top to bottom.*/

/*   void solve(TreeNode* root,int level,vector<int> &ans){
       
    if(!root) return;
    
    if(level==ans.size()){
        ans.push_back(root->val);
    }
    
    solve(root->right,level+1,ans);
    solve(root->left,level+1,ans);
}
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0,ans);
        return ans;
*/

#include <bits/stdc++.h>
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        
        while (!q.empty()) {
            int n = q.size();
            bool flag = true;
            
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (flag) {
                    ans.push_back(temp->val); // Rightmost node of the level
                    flag = false;
                }
                
                if (temp->right) {
                    q.push(temp->right);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
            }
        }
        return ans;
    }
};

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Create Solution object
    Solution sol;
    
    // Call rightSideView function
    vector<int> result = sol.rightSideView(root);
    
    // Print the result
    cout << "Right View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
