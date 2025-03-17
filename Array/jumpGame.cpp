/*55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;  // Tracks the farthest index we can reach

        for (int i = 0; i < n; i++) {
            if (i > maxi) return false;  // If current index is unreachable
            maxi = max(maxi, i + nums[i]);  // Update max reachable index
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example 1: Can reach the last index
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Can jump for nums1: " << (sol.canJump(nums1) ? "true" : "false") << endl;  
    // Expected Output: true

    // Example 2: Cannot reach the last index
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Can jump for nums2: " << (sol.canJump(nums2) ? "true" : "false") << endl;  
    // Expected Output: false

    return 0;
}
