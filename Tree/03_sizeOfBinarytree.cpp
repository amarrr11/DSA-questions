/*Size of Binary Tree
Difficulty: Basic
Given a binary tree of size n, you have to count the number of nodes in it. For example, the count of nodes in the tree below is 4.*/

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
    void size(Node *node, int &cnt) {
        if (node == nullptr) return;

        cnt++;
        size(node->left, cnt);
        size(node->right, cnt);
    }

    int getSize(Node* node) {
        int cnt = 0;
        size(node, cnt);
        return cnt;
    }
    /*int getSize(Node* node) {   //2 lINES CODE
        if(node==NULL) return 0;
        return 1+getSize(node->left)+getSize(node->right);
    }*/
};

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int size = sol.getSize(root);

    // Printing the size of the binary tree
    cout << "Size of the binary tree: " << size << endl;

    return 0;
}
