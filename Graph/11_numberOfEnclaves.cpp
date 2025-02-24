/*1020. Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of
 the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& temp, vector<vector<bool>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        temp[i][j] = 0;

        if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
            dfs(grid, temp, vis, i - 1, j);
        }
        if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
            dfs(grid, temp, vis, i + 1, j);
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
            dfs(grid, temp, vis, i, j - 1);
        }
        if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
            dfs(grid, temp, vis, i, j + 1);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> temp(n, vector<int>(m, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j] && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    dfs(grid, temp, vis, i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 1 && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}
