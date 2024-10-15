/*BST Keys in a Range
Difficulty: Easy
Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

Example 1:

Input:
       17
     /    \
    4     18
  /   \
 2     9 
l = 4, h = 24
Output: 
4 9 17 18 
Example 2:

Input:
       16
     /    \
    7     20
  /   \
 1    10
l = 13, h = 23
Output: 
16 20 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public: 
    void find(Node* root, vector<int>& ans, int low, int high) {
        if (!root) return;

        if (root->data < low) {
            find(root->right, ans, low, high);
        } else if (root->data > high) {
            find(root->left, ans, low, high);
        } else {
            find(root->left, ans, low, high);
            ans.push_back(root->data);
            find(root->right, ans, low, high);
        }
    }

    vector<int> printNearNodes(Node* root, int low, int high) {
        vector<int> ans;
        if (!root) return {};

        find(root, ans, low, high);
        return ans;
    }
};

int main() {
    // Create a binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    Solution solution;

    // Define the range
    int low = 7, high = 15;

    // Get the nodes within the range
    vector<int> result = solution.printNearNodes(root, low, high);

    // Print the result
    cout << "Nodes in the range [" << low << ", " << high << "]: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
