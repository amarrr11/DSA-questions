/*198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it
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
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int i, int n, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(nums, i + 2, n, dp);
        int skip = solve(nums, i + 1, n, dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
    }
     
    //iteratve
    /*int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0,dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip=dp[i-1];

            dp[i]=max(steal,skip);
        }
        return dp[n];
    }*/
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 7, 9, 3, 1};
    cout << "Max amount that can be robbed from nums1: " << solution.rob(nums1) << endl;

    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Max amount that can be robbed from nums2: " << solution.rob(nums2) << endl;

    return 0;
}
