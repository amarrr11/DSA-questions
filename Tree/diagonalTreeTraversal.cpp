/*Diagonal Tree Traversal
Difficulty: Mediu
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging 
to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and 
then right subtree. 

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
unnamed
Diagonal Traversal of binary tree : 
 
 8 10 14 3 6 7 13 1 4*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void find(Node* root, int pos, int &l) {
    if (!root) return;
    
    l = max(l, pos);
    
    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDia(Node* root, vector<vector<int>> &v, int pos) {
    if (!root) return;
    
    v[pos].push_back(root->data);
    
    findDia(root->left, v, pos + 1);
    findDia(root->right, v, pos);
}

vector<int> diagonal(Node* root) {
    vector<int> ans;
    if (!root) return ans;  // Handle empty tree
    
    int l = 0;
    find(root, 0, l);  // Find the maximum diagonal level
    
    vector<vector<int>> v(l + 1);  // Create a 2D vector to store nodes at each diagonal level
    findDia(root, v, 0);  // Populate the diagonal traversal
    
    // Collect nodes into the answer vector
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ans.push_back(v[i][j]);
        }
    }
    
    return ans;
}

// Helper function to insert nodes into the tree
Node* insert(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

int main() {
    Node* root = nullptr;
    
    // Sample tree insertion
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);
    
    // Get the diagonal traversal
    vector<int> result = diagonal(root);
    
    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
