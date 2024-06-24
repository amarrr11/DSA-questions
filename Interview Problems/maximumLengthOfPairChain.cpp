/*646. Maximum Length of Pair Chain

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].*/
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[1] != b[1]) {
            return b[1] > a[1];
        } else {
            return b[0] > a[0];
        }
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);

        int freetime = pairs[0][1];
        int cnt = 1;
        for(int i = 1; i < n; i++) { // Start from the second element
            if(pairs[i][0] > freetime) {
                cnt++;
                freetime = pairs[i][1];
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> pairs1 = {{1, 2}, {2, 3}, {3, 4}};
    cout << "Example 1: " << solution.findLongestChain(pairs1) << endl; // Expected output: 2

    // Example 2
    vector<vector<int>> pairs2 = {{1, 2}, {7, 8}, {4, 5}};
    cout << "Example 2: " << solution.findLongestChain(pairs2) << endl; // Expected output: 3

    // Example 3
    vector<vector<int>> pairs3 = {{5, 6}, {1, 2}, {3, 4}, {2, 3}};
    cout << "Example 3: " << solution.findLongestChain(pairs3) << endl; // Expected output: 2

    return 0;
}
