/*
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, mini = INT_MAX, sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
                int len = j - i + 1;
                mini = min(mini, len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};

int main() {
    Solution sol;
    int target, n;
    cout << "Enter the target sum: ";
    cin >> target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.minSubArrayLen(target, nums);
    cout << "The minimum length of a subarray with sum at least " << target << " is: " << result << endl;

    return 0;
}
