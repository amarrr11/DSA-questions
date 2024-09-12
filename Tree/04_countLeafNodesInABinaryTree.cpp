/*Count Leaves in Binary Tree
Difficulty: Basic
Given a Binary Tree of size N, You have to count leaves in it. For example, there are two leaves in following tree*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leaf(Node* &root, int &cnt) {
    if(root == NULL) return;
    
    if(!root->left && !root->right) {
        cnt++;
    }
    
    leaf(root->left, cnt);
    leaf(root->right, cnt);
}

int countLeaves(Node* root) {
    if(root == NULL) return 0;
  
    int cnt = 0;
    leaf(root, cnt);
    return cnt;

    // if(!root->left and !root->right) return 1;
    
    // return (countLeaves(root->left)+countLeaves(root->right));
}

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    // Counting leaf nodes
    int totalLeaves = countLeaves(root);
    cout << "Total number of leaf nodes: " << totalLeaves << endl;
    
    return 0;
}
