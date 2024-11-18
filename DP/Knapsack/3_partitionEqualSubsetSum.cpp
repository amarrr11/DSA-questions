/*416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements
 in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    bool solve(vector<int> &nums, int target, int idx) {
        if (target == 0) return 1;
        if (target < 0 || idx >= nums.size()) return 0;
        if (dp[target][idx] != -1) return dp[target][idx];
        return dp[target][idx] = solve(nums, target - nums[idx], idx + 1) || solve(nums, target, idx + 1);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return 0;
        dp = vector<vector<int>>(sum / 2 + 1, vector<int>(nums.size(), -1));
        return solve(nums, sum / 2, 0);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};
    if (solution.canPartition(nums)) {
        cout << "Can partition into two subsets with equal sum." << endl;
    } else {
        cout << "Cannot partition into two subsets with equal sum." << endl;
    }
    return 0;
}
