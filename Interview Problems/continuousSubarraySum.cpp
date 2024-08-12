/*523. Continuous Subarray Sum

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
 */

/*Intuition/Approach
Problem Intuition:

The problem is to find whether there exists a subarray of at least two elements in the array nums such that the sum of the subarray is a multiple of a given integer k.
Handling Edge Cases:

If the array has fewer than 2 elements, return false immediately since a valid subarray cannot exist.
Using a Hash Map:

We use an unordered_map (hash map) to keep track of the remainder when the cumulative sum is divided by k and the first index where this remainder occurs.
Cumulative Sum and Remainder:

As we iterate through the array, we calculate the cumulative sum sum up to the current index i.
We then compute the remainder m = sum % k.
Checking for Valid Subarray:

If the remainder m has been seen before (exists in the map), it means that the subarray sum between the previous occurrence of this remainder and the current index is a multiple of k.
Additionally, if the length of this subarray is at least 2 (i.e., i - mp[m] >= 2), return true.
Storing First Occurrence:

If the remainder m has not been seen before, store the current index i in the map against this remainder.
Return False if No Valid Subarray Found:

If no such subarray is found during the iteration, return false.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        unordered_map<int, int> mp;
        mp[0] = -1; 
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int m = sum % k;
            if (mp.find(m) != mp.end()) {
                if (i - mp[m] >= 2) return true;
            } else {
                mp[m] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example 1:
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    if (solution.checkSubarraySum(nums1, k1)) {
        cout << "Example 1: Found a subarray." << endl;
    } else {
        cout << "Example 1: No valid subarray found." << endl;
    }
    
    // Example 2:
    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 13;
    if (solution.checkSubarraySum(nums2, k2)) {
        cout << "Example 2: Found a subarray." << endl;
    } else {
        cout << "Example 2: No valid subarray found." << endl;
    }

    // Example 3:
    vector<int> nums3 = {1, 2, 3};
    int k3 = 5;
    if (solution.checkSubarraySum(nums3, k3)) {
        cout << "Example 3: Found a subarray." << endl;
    } else {
        cout << "Example 3: No valid subarray found." << endl;
    }

    return 0;
}
