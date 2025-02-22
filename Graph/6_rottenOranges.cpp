/*994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 
4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/


#include <bits/stdc++.h>
using namespace std;    
class Solution {
    public:
    
        
        int orangesRotting(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
    
            int fresh=0;
            int time=0;
    
            queue<pair<pair<int,int>,int>> q;
            
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                        q.push({{i,j},0});
                    }else if(grid[i][j]==1){
                        fresh++;
                    }
                }
            }
    
            while(!q.empty()){
                int i=q.front().first.first;
                int j=q.front().first.second;
                time=q.front().second;
    
                q.pop();
                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({{i-1,j},time+1});
                    fresh--;
                }
                if(i+1<n and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({{i+1,j},time+1});
                    fresh--;
                }
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({{i,j-1},time+1});
                    fresh--;
                }
                if(j+1<m and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({{i,j+1},time+1});
                    fresh--;
                }
            }
    
            return fresh==0?time:-1;
        }
    };
    int main() {
        Solution sol;
        
        vector<vector<int>> grid = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
        };
    
        int result = sol.orangesRotting(grid);
        cout << "Minimum time required to rot all oranges: " << result << endl;
    
        return 0;
    }