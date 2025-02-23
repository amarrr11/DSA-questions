/*542. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, time});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            time = q.front().second;
            q.pop();

            if (i - 1 >= 0 && !vis[i - 1][j]) {
                q.push({{i - 1, j}, time + 1});
                ans[i - 1][j] = time + 1;
                vis[i - 1][j] = 1;
            }
            if (i + 1 < n && !vis[i + 1][j]) {
                q.push({{i + 1, j}, time + 1});
                ans[i + 1][j] = time + 1;
                vis[i + 1][j] = 1;
            }
            if (j - 1 >= 0 && !vis[i][j - 1]) {
                q.push({{i, j - 1}, time + 1});
                ans[i][j - 1] = time + 1;
                vis[i][j - 1] = 1;
            }
            if (j + 1 < m && !vis[i][j + 1]) {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = 1;
                ans[i][j + 1] = time + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << "Updated Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
