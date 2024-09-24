/*Vertical Tree Traversal
Difficulty: Medium
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order 
traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6*/

#include <bits/stdc++.h>
using namespace std;

// Definition of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the range of vertical levels
void find(Node* root, int level, int &l, int &r) {
    if (!root) return;
    
    l = min(l, level);
    r = max(r, level);
    
    if (root->left) {
        find(root->left, level - 1, l, r);
    }
    if (root->right) {
        find(root->right, level + 1, l, r);
    }
}

// Function for vertical order traversal
vector<int> verticalOrder(Node *root) {
    vector<int> ans;
    if (!root) return {};
    
    int l = 0, r = 0;
    
    // Finding the vertical range
    find(root, 0, l, r);
    
    vector<vector<int>> positive(r + 1);
    vector<vector<int>> negative(abs(l) + 1);
    
    queue<Node*> q;
    queue<int> index;
    
    q.push(root);
    index.push(0);
    
    // Performing BFS and storing nodes based on their vertical position
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        
        if (pos >= 0) {
            positive[pos].push_back(temp->data);
        } else {
            negative[abs(pos)].push_back(temp->data);
        }
        
        if (temp->left) {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right) {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }
    
    // Collecting results from negative levels
    for (int i = negative.size() - 1; i >= 0; i--) {
        for (int j = 0; j < negative[i].size(); j++) {
            ans.push_back(negative[i][j]);
        }
    }
    
    // Collecting results from positive levels
    for (int i = 0; i < positive.size(); i++) {
        for (int j = 0; j < positive[i].size(); j++) {
            ans.push_back(positive[i][j]);
        }
    }
    
    return ans;
}

// Function to create a sample binary tree and test the vertical order traversal
int main() {
    /* Construct the following binary tree
                1
               / \
              2   3
             / \ / \
            4  6 5  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    
    // Call verticalOrder to get the vertical order traversal
    vector<int> result = verticalOrder(root);
    
    // Output the result
    cout << "Vertical Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
