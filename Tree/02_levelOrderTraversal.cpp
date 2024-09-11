/*Level order traversal
Difficulty: Easy
Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.*/

#include <bits/stdc++.h>
using namespace std;

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
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root) {
        queue<Node*> q;
        vector<int> ans;
        if (root == nullptr) return ans;
        
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            ans.push_back(temp->data);
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        return ans;
    }
};

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.levelOrder(root);

    // Printing the level order traversal
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
