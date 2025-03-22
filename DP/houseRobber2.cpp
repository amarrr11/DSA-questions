/*213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int leaveFirst(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        int ex = leaveFirst(nums, n - 1, dp);
        int in = nums[n] + leaveFirst(nums, n - 2, dp);

        return dp[n] = max(in, ex);
    }

    int leaveLast(vector<int>& nums, int n, vector<int>& dp1) {
        if (n < 0) return 0;

        if (dp1[n] != -1) return dp1[n];

        int ex = leaveLast(nums, n - 1, dp1);
        int in = nums[n] + leaveLast(nums, n - 2, dp1);

        return dp1[n] = max(in, ex);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Single element edge case

        vector<int> dp(n, -1), dp1(n, -1);

        return max(leaveFirst(nums, n - 2, dp), leaveLast(nums, n - 1, dp1));
    }
};

// Main function to test the code
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 3, 2};
    cout << "Maximum amount that can be robbed (Example 1): " << sol.rob(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed (Example 2): " << sol.rob(nums2) << endl;

    return 0;
}
