/*974. Subarray Sums Divisible by K

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long total = 0;
        long long n = nums.size();
        map<long long int, long long int> m;
        long long int sum = 0;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            long long mod = (sum % k + k) % k;
            if (m[mod]) {
                total += m[mod];
                m[mod]++;
            } else {
                m[mod]++;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    
    // Example test case 1
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Number of subarrays divisible by " << k1 << ": " << sol.subarraysDivByK(nums1, k1) << endl;
    
    // Example test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    cout << "Number of subarrays divisible by " << k2 << ": " << sol.subarraysDivByK(nums2, k2) << endl;
    
    return 0;
}
