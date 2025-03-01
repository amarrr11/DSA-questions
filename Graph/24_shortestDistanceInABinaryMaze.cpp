/*Shortest Distance in a Binary Maze

Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given 
source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they 
share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and 
destination cell are based on the zero based indexing. The destination cell should be 1.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if (source == destination) return 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
                        
        vector<int> a = {-1, 0, 1, 0};
        vector<int> b = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int dis = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {   
                int newr = i + a[k];
                int newc = j + b[k];
                
                if (newr >= 0 && newr < n && newc >= 0 && newc < m 
                    && grid[newr][newc] == 1 && 1 + dis < dist[newr][newc]) {
                    
                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                    
                    if (newr == destination.first && newc == destination.second) 
                        return dis + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {
        {1, 1, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };
    pair<int, int> source1 = {0, 0};
    pair<int, int> destination1 = {3, 3};
    cout << "Shortest path length (Example 1): " << sol.shortestPath(grid1, source1, destination1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {1, 1, 1},
        {0, 1, 0},
        {1, 1, 1}
    };
    pair<int, int> source2 = {0, 0};
    pair<int, int> destination2 = {2, 2};
    cout << "Shortest path length (Example 2): " << sol.shortestPath(grid2, source2, destination2) << endl;

    return 0;
}
