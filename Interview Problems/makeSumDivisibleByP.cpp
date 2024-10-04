/*1590. Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining 
elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum 
of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], 
leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.*/

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef long long ll;

    int minSubarray(vector<int>& nums, int p) {
        ll n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % p == 0) return 0;
        unordered_map<ll, ll> mp;
        ll target = sum % p;

        mp[0] = -1;  // Initial condition
        sum = 0;
        ll ans = n;  // Initialize ans with the size of the array

        for (ll i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            ll mod = (sum - target + p) % p;
            if (mp.find(mod) != mp.end()) {
                ll j = mp[mod];
                ans = min(ans, i - j);
            }
            mp[sum] = i;  // Store the current sum mod p with its index
        }

        return ans == n ? -1 : ans;  // If no valid subarray found, return -1
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 4, 2}; // Example input
    int p = 6; // Example p value
    int result = sol.minSubarray(nums, p);

    if (result != -1) {
        cout << "The length of the smallest subarray to remove: " << result << endl;
    } else {
        cout << "No valid subarray found." << endl;
    }

    return 0;
}
