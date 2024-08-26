/*1685. Sum of Absolute Differences in a Sorted Array

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of 
absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        vector<int> postSum(n, 0);
        postSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            postSum[i] = postSum[i + 1] + nums[i];
        }

        int totalSum = preSum[n - 1];
        vector<int> ans(n);
        ans[0] = totalSum - (nums[0] * n);

        for (int i = 1; i < n; i++) {
            ans[i] = (nums[i] * i - preSum[i - 1]) + (postSum[i] - ((n - i) * nums[i]));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 6, 8}; // Example input
    vector<int> result = sol.getSumAbsoluteDifferences(nums);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
