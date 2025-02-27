#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// bool check1(Node* root,int &prev){
//     if(!root) return true;
    
//     if(!check(root->left,prev))return false;

//     if(root->val<=prev){
//         return false;
//     }else{
//         prev=root->val;
//     }
//     if(!check(root->right,prev))return false;
    
//     return true;
// }


bool check(Node *root,int mini,int maxi){
    if(!root) return true;

    if(root->data<=mini or root->data>=maxi){
        return false;
    }
    
    return check(root->left,mini,root->data) and check(root->right,root->data,maxi);
}


int main() {
    // Example BST:
    Node* root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(35);
    root->left->right = new Node(45);
    root->right->left = new Node(55);
    root->right->right = new Node(65);
    root->left->right->left = new Node(41);
    root->left->right->right = new Node(48);
    

    int maxi=INT_MAX;
    int mini=INT_MIN;
    if (check(root, mini, maxi)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
