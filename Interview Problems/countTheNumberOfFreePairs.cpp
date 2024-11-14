/*2563. Count the Number of Fair Pairs

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            auto lower_it = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto upper_it = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            cnt += (upper_it - lower_it);
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 5, 9, 14, 21};
    int lower = 6, upper = 20;
    cout << solution.countFairPairs(nums, lower, upper) << endl;
    return 0;
}
