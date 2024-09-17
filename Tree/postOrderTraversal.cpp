/*Iterative Postorder
Difficulty: Medium
Given a binary tree. Find the postorder traversal of the tree without using recursion. Return a list containing the postorder 
traversal of the tree, calculated without using recursion.

Examples :

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
Explanation: Postorder traversal (Left->Right->Root) of the tree is 4 5 2 3 1.*/

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
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans; // If root is NULL, return empty vector
        }
        
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            
            ans.push_back(temp->data);
            
            if (temp->left) {
                s.push(temp->left);
            }
            if (temp->right) {
                s.push(temp->right);
            }
        }
        reverse(ans.begin(), ans.end()); // Reversing the order to get postorder
        return ans;
    }
};

int main() {
    // Creating a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.postOrder(root);

    // Printing the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
