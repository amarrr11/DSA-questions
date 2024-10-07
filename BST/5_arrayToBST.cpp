/*Array to BST
Difficulty: Easy
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never 
differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will 
be false.

Examples :

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
         4
       /  \
      2    6
     / \   / \
    1   3 5   7
    
*/  

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class containing the methods.
class Solution {
  public:
    Node* solve(vector<int>& nums, int start, int end) {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        Node* newNode = new Node(nums[mid]);

        newNode->left = solve(nums, start, mid - 1);
        newNode->right = solve(nums, mid + 1, end);

        return newNode;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

// Helper function to print the in-order traversal of the BST.
void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    // Example sorted array
    vector<int> nums = {-10, -3, 0, 5, 9};

    // Create Solution object
    Solution sol;

    // Convert sorted array to BST
    Node* bstRoot = sol.sortedArrayToBST(nums);

    // Print the in-order traversal of the BST
    cout << "In-order Traversal of the BST: ";
    inOrder(bstRoot);

    return 0;
}
