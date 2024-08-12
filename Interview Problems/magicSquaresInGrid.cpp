/*840. Magic Squares In Grid

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both 
diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool ismagicGrid(int &r, int &c, vector<vector<int>>& grid) {
        set<int> myset;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || myset.count(num)) {
                    return false;
                } else {
                    myset.insert(num);
                }
            }
        }

        // row sum
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for (int i = 1; i <= 2; i++) {
            int sum2 = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            if (sum2 != sum) return false;
        }
        // col sum
        for (int i = 0; i < 3; i++) {
            int sum2 = grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i];
            if (sum2 != sum) return false;
        }

        // diagonal sums
        int sum1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        if (sum1 != sum) return false;
        int sum2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if (sum2 != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (rows < 3 || cols < 3) return 0;

        int cnt = 0;

        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                if (ismagicGrid(i, j, grid)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2}
    };

    int result = solution.numMagicSquaresInside(grid);
    cout << "Number of magic squares inside the grid: " << result << endl;

    return 0;
}
