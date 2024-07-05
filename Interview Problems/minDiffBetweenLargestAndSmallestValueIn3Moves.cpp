/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        ans = min(ans, nums[n - 4] - nums[0]);
        ans = min(ans, nums[n - 3] - nums[1]);
        ans = min(ans, nums[n - 2] - nums[2]);
        ans = min(ans, nums[n - 1] - nums[3]);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {5, 3, 2, 4};
    vector<int> nums2 = {1, 5, 0, 10, 14};
    vector<int> nums3 = {6, 6, 0, 1, 1, 4, 6};
    vector<int> nums4 = {1, 5, 6, 14, 15};

    cout << "Example 1: " << solution.minDifference(nums1) << endl; // Output: 0
    cout << "Example 2: " << solution.minDifference(nums2) << endl; // Output: 1
    cout << "Example 3: " << solution.minDifference(nums3) << endl; // Output: 2
    cout << "Example 4: " << solution.minDifference(nums4) << endl; // Output: 1

    return 0;
}
