#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->data);
                root = root->right;
            }    
            else {
                Node* curr = root->left;

                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }
                if (curr->right == NULL) {
                    curr->right = root;
                    root = root->left;
                } 
                else {
                    curr->right = NULL;
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Create a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.inOrder(root);

    // Print the in-order traversal result
    cout << "In-order traversal: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
