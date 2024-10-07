/*Sum of k smallest elements in BST
Difficulty: Easy
 Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

Example 1:

Input: 
          20
        /    \
       8     22
     /    \
    4     12
         /    \
        10    14   , K=3

Output: 22
Explanation:
Sum of 3 smallest elements are: 
4 + 8 + 10 = 22
Example 2:
Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8 , K=2

Output: 9
Explanation:
The sum of two smallest elements 
is 4+5=9.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, int &sum, int &k) {
    if (!root) return;

    inorder(root->left, sum, k);

    k--;
    if (k >= 0) {
        sum += root->data;
    }
    if (k <= 0) return;

    inorder(root->right, sum, k);
}

int sum(Node* root, int k) {
    int sum = 0;
    inorder(root, sum, k);
    return sum;
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int k = 3;  // Set the value of k
    int result = sum(root, k);
    
    cout << "Sum of first " << k << " nodes in inorder traversal: " << result << endl;
    
    return 0;
}
