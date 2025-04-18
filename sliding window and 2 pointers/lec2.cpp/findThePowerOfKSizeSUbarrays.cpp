/*3254. Find the Power of K-Size Subarrays I

You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all 
subarrays
 of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

 

Example 1:

Input: nums = [1,2,3,4,3,2,5], k = 3

Output: [3,4,-1,-1,-1]

Explanation:

There are 5 subarrays of nums of size 3:

[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.
Example 2:

Input: nums = [2,2,2,2,2], k = 4

Output: [-1,-1]

Example 3:

Input: nums = [3,2,3,2,3,2], k = 2

Output: [-1,3,-1,3,-1]*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            return nums;
        }
        if (k == 1) {
            return nums;
        }
        
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int maxi = 0;
            bool flag = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != (nums[j - 1] + 1)) {
                    flag = false;
                    break;
                } else {
                    maxi = nums[j];
                }
            }
            if (flag) {
                ans.push_back(maxi);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 2, 3, 5, 6, 7, 9, 10, 11}; // Example array
    int k = 3; // Length of subarray to check

    // Get the result from resultsArray
    vector<int> result = solution.resultsArray(nums, k);

    // Print the output
    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

