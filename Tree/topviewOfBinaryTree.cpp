/*Top View of Binary Tree
Difficulty: Medium
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes
 visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4     5  6      7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same 
position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will
get shadowed.*/

#include <bits/stdc++.h>
using namespace std;

// Definition of Node for the binary tree
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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == nullptr) return ans; // Edge case
        
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        
        q.push({root, 0});
        
        while(!q.empty()) {   
            Node* temp = q.front().first;
            int line = q.front().second;
            q.pop();
            
            // If no entry in map for this line, add it
            if(mp.find(line) == mp.end()) {
                mp[line] = temp->data;
            }
            
            // Traverse the left child
            if(temp->left) {
                q.push({temp->left, line-1});
            }
            
            // Traverse the right child
            if(temp->right) {
                q.push({temp->right, line+1});
            }
        }
        
        // Extracting the top view from the map
        for(auto &it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

// Utility function to insert a new node in the binary tree
Node* insertNode(Node* root, int data) {
    if(root == nullptr) {
        return new Node(data);
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if(temp->left == nullptr) {
            temp->left = new Node(data);
            break;
        } else {
            q.push(temp->left);
        }
        
        if(temp->right == nullptr) {
            temp->right = new Node(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Solution obj;
    vector<int> res = obj.topView(root);
    
    for(int i : res) {
        cout << i << " ";
    }
    
    return 0;
}
