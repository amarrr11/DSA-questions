/*3355. Zero Array Transformation I

You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise
 return false.

A subset of an array is a selection of elements (possibly none) of the array.

 

Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> sweep(n + 1, 0);

        for (auto& it : q) {
            sweep[it[0]]++;
            if (it[1] + 1 < n) {
                sweep[it[1] + 1] -= 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            sweep[i] += sweep[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (sweep[i] < nums[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {2, 3, 1, 4};  // Example array
    vector<vector<int>> q = {{0, 1}, {1, 2}, {2, 3}};  // Example queries
    
    bool result = solution.isZeroArray(nums, q);

    if (result) {
        cout << "The array can be reduced to all zeros." << endl;
    } else {
        cout << "The array cannot be reduced to all zeros." << endl;
    }

    return 0;
}
