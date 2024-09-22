/*Left View of Binary Tree
Difficulty: Easy
Given a Binary Tree, return its Left view. The left view of a Binary Tree is a set of nodes visible when the tree is visited 
from the Left side. If no left view is possible, return an empty array.

Examples :

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, 8]
          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   
Output: [1, 2, 4, 8]
Explanation: When we view the tree from the left side, we can only see the nodes 1, 2, 4, and 8.
Input: root[] = [1, 3, N, N, 4]
Output: [1, 3, 4]*/

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

vector<int> leftView(Node *root) {
    if (!root) return {};
    
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    
    while (!q.empty()) {
        int n = q.size();
        bool flag = true;
        
        while (n--) {
            Node* temp = q.front();
            q.pop();
            
            if (flag) {
                ans.push_back(temp->data);
                flag = false;
            }
            
            if (temp->left) {
                q.push(temp->left); 
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return ans;
}

int main() {
    // Create the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    // Call leftView function
    vector<int> result = leftView(root);
    
    // Print the result
    cout << "Left View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
