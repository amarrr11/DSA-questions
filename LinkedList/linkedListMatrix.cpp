/*Linked List Matrix
Difficulty: Easy
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* right;
    Node* down;
    
    Node(int val) : data(val), right(nullptr), down(nullptr) {}
};

// Class with the constructLinkedMatrix function
class Matrix {
public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<Node*>> ans(n, vector<Node*>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Node *node = new Node(mat[i][j]);
                ans[i][j] = node;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n - 1) {
                    ans[i][j]->down = nullptr;
                } else {
                    ans[i][j]->down = ans[i + 1][j];
                }
                if (j == m - 1) {
                    ans[i][j]->right = nullptr;
                } else {
                    ans[i][j]->right = ans[i][j + 1];
                }
            }
        }
        return ans[0][0];  // Return the head of the linked matrix
    }
};

// Function to print the linked matrix
void printLinkedMatrix(Node* head) {
    Node* downPtr = head;
    
    while (downPtr != nullptr) {
        Node* rightPtr = downPtr;
        
        while (rightPtr != nullptr) {
            cout << rightPtr->data << " ";
            rightPtr = rightPtr->right;
        }
        cout << endl;
        downPtr = downPtr->down;
    }
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Create the Matrix object and construct the linked matrix
    Matrix matrixObj;
    Node* linkedMatrixHead = matrixObj.constructLinkedMatrix(mat);
    
    // Print the linked matrix
    cout << "Linked matrix: " << endl;
    printLinkedMatrix(linkedMatrixHead);
    
    return 0;
}
