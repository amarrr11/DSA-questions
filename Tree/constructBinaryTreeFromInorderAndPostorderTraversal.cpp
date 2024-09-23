/*Binary Tree from Inorder and Postorder
Difficulty: Medium
Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task
 is to construct a unique binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Note:- The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

Examples:

Input: n = 8, in[] = [4, 8, 2, 5, 1, 6, 3, 7], post[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8
Input: n = 5, in[] = [9, 5, 2, 3, 4], post[] = [5, 9, 3, 4, 2]
Output: 2 9 5 4 3
Explanation: The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
         
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

    Node* solve(int in[], int post[], int inStart, int inEnd, int index) {
        if(inStart > inEnd) return NULL;

        Node* root = new Node(post[index]);

        int pos = find(in, inStart, inEnd, post[index]);

        root->right = solve(in, post, pos + 1, inEnd, index - 1);
        root->left = solve(in, post, inStart, pos - 1, index - (inEnd - pos) - 1);

        return root;
    }

    // Function to return a tree created from postorder and inorder traversals.
    Node* buildTree(int n, int in[], int post[]) {
        return solve(in, post, 0, n - 1, n - 1);
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

    int in[n], post[n];

    cout << "Enter inorder traversal: ";
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }

    cout << "Enter postorder traversal: ";
    for(int i = 0; i < n; i++) {
        cin >> post[i];
    }

    Node* root = sol.buildTree(n, in, post);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
