/*Construct BST from Postorder
Difficulty: Easy
Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be 
inorder traversal of the constructed BST.

Example 1:

Input:
6
1 7 5 50 40 10

Output:
1 5 7 10 40 50

Explanation:
Testcase 1: The BST for the given post order traversal is:


Thus the inorder traversal of BST is: 1 5 7 10 40 50.*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* BST(int post[], int &index, int lower, int upper, int size) {
    if(index == size || post[index] < lower || post[index] > upper) {
        return NULL;
    }

    Node* node = new Node(post[index++]);
    node->right = BST(post, index, node->data, upper, size);
    node->left = BST(post, index, lower, node->data, size);
    return node;
}

Node* constructTree(int post[], int size) {
    reverse(post, post + size);
    int index = 0;
    return BST(post, index, INT_MIN, INT_MAX, size);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int post[] = {1, 7, 5, 50, 40, 10}; // example postorder array
    int size = sizeof(post) / sizeof(post[0]);

    Node* root = constructTree(post, size);

    cout << "Inorder Traversal of constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
