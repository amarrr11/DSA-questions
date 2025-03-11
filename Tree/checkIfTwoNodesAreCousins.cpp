/*Check if two Nodes are Cousins
Difficulty: Medium
Given a binary tree (having distinct node values)root and two node values. Check whether or not the two nodes with values a and b are cousins.
Note: Two nodes of a binary tree are cousins if they have the same depth with different parents.

Example 1:

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: false
Explanation: Here, nodes 2 and 3 areat the same level but have sameparent nodes.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
class Solution {
public:
    TreeNode* xpar=NULL,*ypar=NULL;
    int xlvl,ylvl;
    void dfs(TreeNode* root,TreeNode* parent, int a, int b,int lvl){
        if(!root or (xpar!=NULL and  ypar!=NULL) or (xlvl!=-1 and ylvl!=-1)) return;

        if(root->val==a){
            xpar=parent;
            xlvl=lvl;
        }
        if(root->val==b){
            ypar=parent;
            ylvl=lvl;
        }

        dfs(root->left,root,a,b,lvl+1);
        dfs(root->right,root,a,b,lvl+1);

    }
    bool isCousins(TreeNode* root, int a, int b) {
        
        dfs(root,NULL,a,b,0) ;
        if(xpar!=ypar and xlvl==ylvl){
            return true;
        }
        return false;

*/

bool isCousins(Node* root, int a, int b) {
    queue<Node*> q;
    q.push(root);
    
    int founda = 0, foundb = 0, foundab = 0, diffparent = 1;
    
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node* temp = q.front();
            q.pop();
            
            if (temp->data == a) {
                founda = 1;
            }
            if (temp->data == b) {
                foundb = 1;
            }
            
            if (founda && foundb) {
                foundab = 1;
            }
            
            if (temp->left && temp->right) {
                if ((temp->left->data == a && temp->right->data == b) ||
                    (temp->left->data == b && temp->right->data == a)) {
                    diffparent = 0;
                }
            }
            
            if (foundab && diffparent) {
                return true;
            }
            
            if (temp->left) {
                q.push(temp->left);
            }
            
            if (temp->right) {
                q.push(temp->right);
            }
        }
        founda = 0;
        foundb = 0;
    }
    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    
    int a = 4, b = 5;
    
    if (isCousins(root, a, b)) {
        cout << a << " and " << b << " are cousins." << endl;
    } else {
        cout << a << " and " << b << " are not cousins." << endl;
    }
    
    return 0;
}
