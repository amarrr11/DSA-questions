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

vector<int> preOrder(Node* root)
{   
    vector<int> ans;
    while(root)
    {
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }    
        else{
            Node *curr = root->left;

            while(curr->right && curr->right != root){
                curr = curr->right;
            }
            if(curr->right == NULL){
                curr->right = root;
                ans.push_back(root->data);
                root = root->left;
            }
            else{
                curr->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}

int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calling preOrder traversal function
    vector<int> result = preOrder(root);

    // Outputting the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
