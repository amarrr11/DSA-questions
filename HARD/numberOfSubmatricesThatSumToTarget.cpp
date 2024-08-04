/* 1074. Number of Submatrices That Sum to Target

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: 
for example, if x1 != x1'.

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Make prefix sum for all rows
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        // Find the number of subarrays in 2-D
        int ans = 0;
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int i = startCol; i < cols; i++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int cSum = 0; // Cumulative sum
                for (int j = 0; j < rows; j++) {
                    cSum += mat[j][i] - (startCol > 0 ? mat[j][startCol - 1] : 0);
                    if (mp[cSum - target]) {
                        ans += mp[cSum - target];
                    }
                    mp[cSum]++;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Initialize the matrix and target value
    vector<vector<int>> matrix = {
        {1, -1, 0},
        {1, -1, 0},
        {1, -1, 0}
    };
    int target = 0;

    // Create an instance of the Solution class
    Solution solution;

    // Call the numSubmatrixSumTarget function
    int result = solution.numSubmatrixSumTarget(matrix, target);

    // Print the result
    cout << "Number of submatrices that sum to " << target << ": " << result << endl;

    return 0;
}
