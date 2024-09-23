/*Construct Tree from Inorder & Preorder
Difficulty: Medium
Given two arrays of inorder and preorder traversal of size n. Construct a tree using the inorder and preorder arrays and 
return the root node of the constructed tree.

Example 1:

Input:
n = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
n = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
*/

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

    int find(int in[], int inStart, int inEnd, int num) {
        for(int i = inStart; i <= inEnd; i++) {
            if(in[i] == num) {
                return i;
            }
        }
        return -1;
    }

    Node* solve(int in[], int pre[], int inStart, int inEnd, int index) {
        if(inStart > inEnd) return NULL;

        Node* root = new Node(pre[index]);

        int pos = find(in, inStart, inEnd, pre[index]);

        root->left = solve(in, pre, inStart, pos - 1, index + 1);
        root->right = solve(in, pre, pos + 1, inEnd, index + (pos - inStart) + 1);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        return solve(in, pre, 0, n - 1, 0);
    }
};

void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int in[n], pre[n];

    cout << "Enter inorder traversal: ";
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }

    cout << "Enter preorder traversal: ";
    for(int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    Node* root = sol.buildTree(in, pre, n);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
