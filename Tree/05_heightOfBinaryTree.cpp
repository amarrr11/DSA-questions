#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    //Function to find the height of a binary tree.
    int height(Node* node) {
        if (node == NULL) return 0;

        if (!node->left && !node->right) {
            return 1;
        }

        return 1 + max(height(node->left), height(node->right));
    }
};

int main() {
    // Creating a simple binary tree:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int treeHeight = sol.height(root);
    cout << "Height of the binary tree is: " << treeHeight << endl;

    return 0;
}
