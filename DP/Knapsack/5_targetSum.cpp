/*494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then 
concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression
 "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[25][1005];
    
    int solve(vector<int>& nums, int target, int idx, int sum) {
        if(idx == nums.size()) {
            return sum == target;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];

        int take = solve(nums, target, idx + 1, sum + nums[idx]);
        int notTake = solve(nums, target, idx + 1, sum - nums[idx]);

        return dp[idx][sum] = (take + notTake);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0, 0);   
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    
    cout << "Number of ways to reach target: " << sol.findTargetSumWays(nums, target) << endl;
    
    return 0;
}
