/*Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 93K+Points: 4Average Time: 20m
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s 
(horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not 
equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.*/

#include <bits/stdc++.h>
using namespace std;

set<vector<pair<int, int>>> s;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &v, int i, int j, int row, int col)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j] = 1;

    v.push_back({row - i, col - j});

    if (i - 1 >= 0 && grid[i - 1][j] == 1 && !vis[i - 1][j])
    {
        dfs(grid, vis, v, i - 1, j, row, col);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1 && !vis[i][j - 1])
    {
        dfs(grid, vis, v, i, j - 1, row, col);
    }
    if (i + 1 < n && grid[i + 1][j] == 1 && !vis[i + 1][j])
    {
        dfs(grid, vis, v, i + 1, j, row, col);
    }
    if (j + 1 < m && grid[i][j + 1] == 1 && !vis[i][j + 1])
    {
        dfs(grid, vis, v, i, j + 1, row, col);
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> v;
                dfs(grid, vis, v, i, j, i, j);
                s.insert(v);
            }
        }
    }

    return s.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}};

    cout << "Number of distinct islands: " << countDistinctIslands(grid) << endl;

    return 0;
}
