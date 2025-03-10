/*3208. Alternating Groups II

There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

Example 1:

Input: colors = [0,1,0,1,0], k = 3

Output: 3

Explanation:



Alternating groups:



Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        int i = 0, j = 0;

        // Extending the array to handle circular property
        for (int x = 0; x < k - 1; x++) {
            colors.push_back(colors[x]);
        }

        while (j < colors.size()) {
            if (j > 0 && colors[j] == colors[j - 1]) {
                i = j;  // Reset start of the window
            }
            if (j - i + 1 == k) {
                cnt++;  // Valid alternating group found
                i++;  // Slide the window forward
            }
            j++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> colors1 = {1, 2, 1, 2, 3};
    int k1 = 3;
    cout << "Test 1: " << sol.numberOfAlternatingGroups(colors1, k1) << endl; // Expected output: 3

    // Example 2
    vector<int> colors2 = {1, 1, 2, 2, 3, 3};
    int k2 = 2;
    cout << "Test 2: " << sol.numberOfAlternatingGroups(colors2, k2) << endl; // Expected output: 0

    // Example 3
    vector<int> colors3 = {1, 2, 3, 4, 5};
    int k3 = 4;
    cout << "Test 3: " << sol.numberOfAlternatingGroups(colors3, k3) << endl; // Expected output: 2

    return 0;
}
