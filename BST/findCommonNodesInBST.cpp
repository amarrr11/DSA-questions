/*Find Common Nodes in two BSTs
Difficulty: Medium
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Example 1:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9
Output: 4 7 9 10

Example 2:

Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3*/

#include <iostream>
#include <vector>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find the nodes that are common in both BSTs.
void solve(Node* r1, vector<int>& ans1) {
    if (!r1) return;
    
    solve(r1->left, ans1);
    ans1.push_back(r1->data);
    solve(r1->right, ans1);
}

void solve1(Node* r2, vector<int>& ans2) {
    if (!r2) return;
    
    solve1(r2->left, ans2);
    ans2.push_back(r2->data);
    solve1(r2->right, ans2);
}

vector<int> findCommon(Node* root1, Node* root2) {
    vector<int> ans;
    vector<int> ans1;
    vector<int> ans2;
    solve(root1, ans1);
    solve1(root2, ans2);
    int i = 0, j = 0;
    while (i < ans1.size() && j < ans2.size()) {
        if (ans1[i] == ans2[j]) {
            ans.push_back(ans1[i]);
            i++;
            j++;
        } else if (ans1[i] > ans2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return ans;
}

// Function to insert a new node in the BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    // Create two BSTs
    Node* root1 = nullptr;
    Node* root2 = nullptr;
    
    // Inserting elements in first BST
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1, 0);
    root1 = insert(root1, 4);
    root1 = insert(root1, 7);
    root1 = insert(root1, 9);
    
    // Inserting elements in second BST
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
    
    // Find common nodes in both BSTs
    vector<int> commonNodes = findCommon(root1, root2);
    
    // Output the common nodes
    cout << "Common Nodes: ";
    for (int val : commonNodes) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
