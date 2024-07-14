/*153. Find Minimum in Rotated Sorted Array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        //take mi from the sorted array and keep repeating .
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            } else if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {11, 13, 15, 17},
        {2, 2, 2, 0, 1},
        {1}
    };
    
    for (const auto& testCase : testCases) {
        cout << "Minimum element in { ";
        for (int num : testCase) {
            cout << num << " ";
        }
        cout << "} is " << sol.findMin(const_cast<vector<int>&>(testCase)) << endl;
    }

    return 0;
}
