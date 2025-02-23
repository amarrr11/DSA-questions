/*130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells 
are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board.


Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, vector<vector<char>>& grid, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        vis[i][j] = 1;
        grid[i][j] = 'O';

        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !vis[i - 1][j]) {
            dfs(board, vis, grid, i - 1, j);
        }
        if (i + 1 < n && board[i + 1][j] == 'O' && !vis[i + 1][j]) {
            dfs(board, vis, grid, i + 1, j);
        }
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !vis[i][j - 1]) {
            dfs(board, vis, grid, i, j - 1);
        }
        if (j + 1 < m && board[i][j + 1] == 'O' && !vis[i][j + 1]) {
            dfs(board, vis, grid, i, j + 1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<char>> grid(n, vector<char>(m, 'X'));

        // Step 1: Apply DFS on border 'O' cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O' && !vis[i][j]) {
                    dfs(board, vis, grid, i, j);
                }
            }
        }

        // Step 2: Copy the grid values back to board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = grid[i][j];
            }
        }
    }
};

// Helper function to print the board
void printBoard(vector<vector<char>>& board) {
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:\n";
    printBoard(board);

    Solution obj;
    obj.solve(board);

    cout << "\nProcessed Board:\n";
    printBoard(board);

    return 0;
}
