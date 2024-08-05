/*525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

/*Intuition:
To solve this problem, we need to transform the array in such a way that it becomes easier to find subarrays with an equal
 number of 0s and 1s. A useful transformation is to change every 0 in the array to -1. This way, finding a subarray with 
 equal numbers of 0s and 1s is equivalent to finding a subarray with a sum of 0.

Approach:
Transform the Problem:

Convert the problem of finding a subarray with equal numbers of 0s and 1s into a problem of finding a subarray with a sum of 0.
To achieve this, iterate through the array and treat 0s as -1 and 1s as 1.
Use a HashMap to Track Prefix Sums:

Use a hash map (mp) to store the first occurrence of each prefix sum.
The key in the hash map will be the prefix sum, and the value will be the index at which this sum first occurs.
Iterate through the Array:

Maintain a running sum (sum), which is incremented by 1 for every 1 encountered and decremented by 1 for every 0 encountered.
For each element in the array:
Update the running sum.
Check if this sum has been seen before (i.e., it exists in the hash map):
If it has been seen before, calculate the length of the subarray from the previous occurrence of this sum to the current 
index and update the maximum length (ans) if this subarray is longer than the current maximum.
If it hasn't been seen before, store the current index in the hash map with the current sum as the key.
Return the Maximum Length:

After iterating through the array, return the maximum length of the subarray with equal numbers of 0s and 1s.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] == 1 ? sum += 1 : sum -= 1;
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Define test cases
    vector<vector<int>> testCases = {
        {0, 1},             // Expected output: 2
        {0, 1, 0},          // Expected output: 2
        {0, 0, 1, 0, 0, 1, 1}, // Expected output: 6
        {1, 1, 1, 0, 1, 1, 0, 0}, // Expected output: 4
        {1, 0, 1, 1, 0, 0, 1, 1} // Expected output: 8
    };

    // Process each test case
    for (const auto& testCase : testCases) {
        cout << "Input: ";
        for (const auto& num : testCase) {
            cout << num << " ";
        }
        cout << "\n";
        int result = solution.findMaxLength(testCase);
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}
