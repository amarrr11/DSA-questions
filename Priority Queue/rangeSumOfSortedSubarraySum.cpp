/*1508. Range Sum of Sorted Subarray Sums

You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays
 from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the 
answer can be a huge number return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the
 new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of
 the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int M = 1e9 + 7;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        int sum = 0;
        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();

            int ele = p.first;
            int idx = p.second;

            if (i >= left) {
                sum = (sum + ele) % M;
            }

            if (idx + 1 < n) {
                pq.push({ele + nums[idx + 1], idx + 1});
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {1, 2, 3, 4}; // Example array
    int n = nums.size(); // Size of the array
    int left = 1; // Starting index for the range sum
    int right = 5; // Ending index for the range sum

    // Call the rangeSum function
    int result = solution.rangeSum(nums, n, left, right);
    
    // Output the result
    cout << "The range sum is: " << result << endl;

    return 0;
}
