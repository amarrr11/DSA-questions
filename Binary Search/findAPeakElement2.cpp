/*1901. Find a Peak Element II

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right,
 top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the
length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:

Input: mat = [[1,4],[3,2]]  
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:

Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int n, int m, int col) {
        int row;
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = maxElement(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 <= m - 1 ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main() {
    // Example matrix for testing
    vector<vector<int>> mat = {
        {1, 4, 3, 6},
        {7, 8, 9, 5},
        {10, 11, 13, 12}
    };

    Solution sol;
    vector<int> peak = sol.findPeakGrid(mat);

    // Output the result
    if (peak[0] != -1 && peak[1] != -1) {
        cout << "Peak element found at row " << peak[0] << " and column " << peak[1] << " with value " << mat[peak[0]][peak[1]] << endl;
    } else {
        cout << "No peak element found." << endl;
    }

    return 0;
}
