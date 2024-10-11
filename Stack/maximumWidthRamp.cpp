/*962. Maximum Width Ramp

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
    
        // Populate the stack
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(nums[i]);
            }
            else if (nums[i] >= s.top()) {
                s.push(nums[i]);
            } else {
                s.push(s.top());
            }
        }

        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        int i = 0;
        int j = 0;
        int ans = 0;

        // Calculate the maximum width ramp
        while (i < n && j < n) {
            while (j < n && nums[i] <= v[j]) {
                ans = max(ans, j - i);
                j++;
            }
            i++;
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {6, 0, 8, 2, 1, 5};
    cout << "Max Width Ramp (Test Case 1): " << solution.maxWidthRamp(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << "Max Width Ramp (Test Case 2): " << solution.maxWidthRamp(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {5, 5, 5, 5, 5, 5};
    cout << "Max Width Ramp (Test Case 3): " << solution.maxWidthRamp(nums3) << endl;

    return 0;
}
