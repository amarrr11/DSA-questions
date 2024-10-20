/*240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the 
following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        // if(n == 0) return false;
        int m = mat[0].size();
        // if(m == 0) return false;

        int low = 0;
        int high = m - 1; // stand at end column

        while (low < n && high >= 0) {
            if (mat[low][high] == target) return true;
            else if (mat[low][high] > target) high--;
            else low++;
        }
        return false;
    }
};

int main() {
    int rows, cols, target;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    bool found = solution.searchMatrix(matrix, target);

    if (found) {
        cout << "Target found in the matrix.\n";
    } else {
        cout << "Target not found in the matrix.\n";
    }

    return 0;
}
