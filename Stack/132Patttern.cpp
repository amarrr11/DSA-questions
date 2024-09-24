/*456. 132 Pattern

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that 
i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();     // Get the size of the array
        int s3 = INT_MIN;        // Initialize s3 to the smallest possible value

        stack<int> s;            // Stack to track possible candidates for the 132 pattern
        for (int i = n - 1; i >= 0; i--) {   // Traverse the array from the right to left
            // Check if we've found a 132 pattern where nums[i] is smaller than s3 (pattern is complete)
            if (s3 > nums[i]) return true;

            // While stack is not empty and top of the stack is less than current element nums[i]
            while (!s.empty() && s.top() < nums[i]) {
                s3 = s.top();   // Update s3 to the value being popped (potential '2' in the pattern)
                s.pop();        // Remove the top element from the stack
            }

            // Push current element nums[i] onto the stack (potential '3' in the pattern)
            s.push(nums[i]);
        }
        // Return false if no 132 pattern is found
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {3, 1, 4, 2};

    // Call the function to check for 132 pattern and store the result
    bool has132Pattern = solution.find132pattern(nums);

    // Output the result
    if (has132Pattern) {
        cout << "The array contains a 132 pattern." << endl;
    } else {
        cout << "The array does not contain a 132 pattern." << endl;
    }

    return 0;
}
