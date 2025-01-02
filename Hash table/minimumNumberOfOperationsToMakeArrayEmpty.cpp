/*2870. Minimum Number of Operations to Make Array Empty

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

 

Example 1:

Input: nums = [2,3,3,2,2,4,2,3,4]
Output: 4
Explanation: We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.
Example 2:

Input: nums = [2,1,2,2,3,3]
Output: -1
Explanation: It is impossible to empty the array.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int &i : nums) {
            mp[i]++;
        } 
        int cnt = 0;

        // Process each number's frequency
        for (auto &it : mp) {
            if (it.second == 0) continue;

            while (it.second % 3 != 0) {
                cnt++;
                it.second -= 2;
                if (it.second == 0) break;
                if (it.second == 1) return -1;  // Can't proceed further with 1 remaining
            }
            
            // Once divisible by 3, divide it
            if (it.second % 3 == 0 && it.second > 0) {
                cnt += it.second / 3;
                it.second = 0;
            }
        }

        // Check if any element's frequency is still not reduced to 0
        for (auto &it : mp) {
            if (it.second != 0) return -1;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 1, 1, 1, 1, 1};
    cout << "Example 1: " << sol.minOperations(nums1) << endl;  // Output: -1
    
    // Example 2
    vector<int> nums2 = {2, 2, 2, 2, 2, 2};
    cout << "Example 2: " << sol.minOperations(nums2) << endl;  // Output: 2
    
    // Example 3
    vector<int> nums3 = {3, 3, 3};
    cout << "Example 3: " << sol.minOperations(nums3) << endl;  // Output: 1

    return 0;
}
