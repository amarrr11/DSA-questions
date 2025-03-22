/*554. Brick Wall

There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

 

Example 1:


Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
Example 2:

Input: wall = [[1],[1],[1]]
Output: 3*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int leastBricks(vector<vector<int>>& wall) {
        ll n = wall.size();
        unordered_map<ll, ll> mp;
        
        for (ll i = 0; i < n; i++) {
            ll sum = 0;
            for (ll j = 0; j < wall[i].size() - 1; j++) { // Exclude last brick
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        
        ll ans = 0;
        for (auto it : mp) {
            ans = max(ans, it.second); // Find max edges frequency
        }
        
        return n - ans; // Minimum bricks crossed
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    vector<vector<int>> wall1 = {
        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };
    cout << "Test Case 1 Output: " << sol.leastBricks(wall1) << endl; // Expected Output: 2

    vector<vector<int>> wall2 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "Test Case 2 Output: " << sol.leastBricks(wall2) << endl; // Expected Output: 3

    return 0;
}
