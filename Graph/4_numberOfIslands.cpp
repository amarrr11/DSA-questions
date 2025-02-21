/*200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four
 edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if (i - 1 >= 0 && grid[i - 1][j] == '1' && !vis[i - 1][j]) {
                vis[i - 1][j] = 1;
                q.push({i - 1, j});
            }
            if (i + 1 < n && grid[i + 1][j] == '1' && !vis[i + 1][j]) {
                vis[i + 1][j] = 1;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1' && !vis[i][j - 1]) {
                vis[i][j - 1] = 1;
                q.push({i, j - 1});
            }
            if (j + 1 < m && grid[i][j + 1] == '1' && !vis[i][j + 1]) {
                vis[i][j + 1] = 1;
                q.push({i, j + 1});
            }
        }
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    bfs(i, j, vis, grid, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}