/*Bottom View of Binary Tree
Difficulty: Medium
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level 
traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance 
of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.*/

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
