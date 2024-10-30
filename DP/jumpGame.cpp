/*55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the 
array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible 
to reach the last index.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[10001];

    bool solve(vector<int>& nums, int index, int n) {
        if (index == n - 1) return true;    // Base case: reached the last index
        if (index >= n) return false;       // Out of bounds

        if (memo[index] != -1) return memo[index]; // Return cached result if available

        // Check all jumps possible from the current index
        for (int i = 1; i <= nums[index]; i++) {
            if (index + i >= n) continue;   // Ensure we don't go out of bounds
            if (solve(nums, index + i, n)) { // Recursively check if we can reach the end
                return memo[index] = true;    // Store result in memo
            }
        }
        return memo[index] = false;           // No valid path found
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));       // Initialize memo array with -1
        return solve(nums, 0, n);              // Start solving from index 0
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};     // Example input
    bool result = sol.canJump(nums);        // Call the function
    cout << (result ? "Can Jump" : "Cannot Jump") << endl; // Output result
    return 0;
}
