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
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        stack<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.top();
            q.pop();
            
            ans.push_back(temp->data);
            
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
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
    vector<int> result = sol.preOrder(root);

    // Printing the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
