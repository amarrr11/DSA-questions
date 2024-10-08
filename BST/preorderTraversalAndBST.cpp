/*Preorder Traversal and BST
Difficulty: Medium
Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent
 preorder traversal of a possible BST, else returns 0.

Example 1:

Input:
N = 3
arr = {2, 4, 3}
Output: 1
Explaination: Given arr[] can represent
preorder traversal of following BST:
               2
                \
                 4
                /
               3
Example 2:

Input:
N = 3
Arr = {2, 4, 1}
Output: 0
Explaination: Given arr[] cannot represent
preorder traversal of a BST.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(NULL), right(NULL) {}
    };

    void solve(int arr[], int &index, int start, int end, int n) {
        if (index == n || arr[index] < start || arr[index] > end) {
            return;
        }

        Node* node = new Node(arr[index++]);
        solve(arr, index, start, node->data, n);
        solve(arr, index, node->data, end, n);
    }

    int canRepresentBST(int arr[], int n) {
        int index = 0;
        solve(arr, index, INT_MIN, INT_MAX, n);
        return index == n;
    }
};

int main() {
    Solution sol;
    int arr[] = {10, 5, 1, 7, 40, 50}; // Example input array representing a preorder traversal
    int n = sizeof(arr) / sizeof(arr[0]);

    if (sol.canRepresentBST(arr, n)) {
        cout << "The array can represent a BST in preorder." << endl;
    } else {
        cout << "The array cannot represent a BST in preorder." << endl;
    }

    return 0;
}
