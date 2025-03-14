/*Sum Tree

Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples:

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Input:
   25
  /   \    
 9     15
Output: false*/

#include <iostream>
using namespace std;

// Definition for a binary tree node
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
    bool isSumTree(Node* root) {
        if (!root) {
            return true;
        }
        if (!root->left && !root->right) {
            return true;
        }

        bool left = isSumTree(root->left);
        bool right = isSumTree(root->right);

        int lsum = (root->left) ? root->left->data : 0;
        int rsum = (root->right) ? root->right->data : 0;

        if (left && right && root->data == (lsum + rsum)) {
            return true;
        }
        return false;
    }
};

// Function to test the isSumTree function
int main() {
    /*
        Example Tree:
              26
             /  \
           10    3
          /  \    \
         4    6    3
    */
    
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution solution;
    if (solution.isSumTree(root)) {
        cout << "The given tree is a Sum Tree.\n";
    } else {
        cout << "The given tree is NOT a Sum Tree.\n";
    }

    return 0;
}
