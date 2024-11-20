/*198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the
 only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it 
 will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob
 tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        // Base case: if index is out of bounds, return 0
        if (idx >= nums.size()) return 0;

        // If already computed, return the stored result
        if (dp[idx] != -1) return dp[idx];
        
        // Case 1: Rob the current house and skip the next one
        int select = nums[idx] + solve(nums, idx + 2, dp);
        
        // Case 2: Skip the current house and consider the next house
        int notSelect = solve(nums, idx + 1, dp);
        
        // Store and return the maximum of both cases
        return dp[idx] = max(select, notSelect); 
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // Initialize memoization array
        return solve(nums, 0, dp);       // Start from the first house
    }
};

int main() {
    // Initialize the Solution object
    Solution solution;

    // Example input: the amount of money in each house
    vector<int> houses = {2, 7, 9, 3, 1};

    // Call the rob function and print the result
    int maxMoney = solution.rob(houses);
    cout << "Maximum money that can be robbed: " << maxMoney << endl;

    return 0;
}
