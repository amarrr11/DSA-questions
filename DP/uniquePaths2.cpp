/*63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square 
that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int sr, int sc, int er, int ec, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (sr > er || sc > ec) return 0;
        if (grid[sr][sc] == 1) return 0;
        if (sr == er && sc == ec) return 1;

        if (memo[sr][sc] != -1) return memo[sr][sc];

        int rightWays = solve(sr, sc + 1, er, ec, grid, memo);
        int downWays = solve(sr + 1, sc, er, ec, grid, memo);

        memo[sr][sc] = rightWays + downWays;
        return memo[sr][sc];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(0, 0, n - 1, m - 1, grid, memo);
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution solution;
    int result = solution.uniquePathsWithObstacles(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
