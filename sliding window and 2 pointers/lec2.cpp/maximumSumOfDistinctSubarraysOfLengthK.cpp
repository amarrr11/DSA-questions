/*2461. Maximum Sum of Distinct Subarrays With Length K

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // For accumulate function

using namespace std;

class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll sum = accumulate(nums.begin(), nums.begin() + k, 0LL); 
        ll maxsum = 0;
        ll n = nums.size();
        unordered_map<ll, ll> mp;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        if (mp.size() == k) {
            maxsum = sum;
        }

        ll i = 0;
        ll j = k;

        while (j < n) {
            sum -= nums[i];
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            sum += nums[j];
            mp[nums[j]]++;

            if (mp.size() == k) {
                maxsum = max(sum, maxsum);
            }

            i++;
            j++;
        }
        return maxsum;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1, 2, 3};
    int k = 3;

    // Create an instance of Solution and call the function
    Solution sol;
    long long result = sol.maximumSubarraySum(nums, k);

    // Output the result
    cout << "Maximum subarray sum with " << k << " distinct elements: " << result << endl;

    return 0;
}
