/*3255. Find the Power of K-Size Subarrays II

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

/*
Intuition and Approach:

1. Problem Understanding:
   - We need to find out if there are any breaks (non-consecutive elements) in each sliding window of size `k`.
   - If there are no breaks in the window, return the last element of that window.
   - If there is a break, return `-1`.

2. Initialize Variables:
   - `arr`: A vector of size `n` (size of `nums`) initialized to 0. It will store whether there is a break in the sequence at
    each position.
   - `cnt`: A counter to keep track of the number of breaks in the current window.

3. Mark Breaks in Sequence:
   - Traverse the `nums` array starting from the second element.
   - If the current element `nums[i]` is not consecutive to the previous one `nums[i-1]`, mark a break in `arr[i]` by setting
    `arr[i] = 1`.

4. Initial Window Setup:
   - Calculate the initial number of breaks (`cnt`) for the first window of size `k`.
   - Traverse the first `k` elements and count the breaks in this window.

5. Sliding Window Logic:
   - Start a loop from `i = k` to `i < n` to slide the window across the array.
   - For each new position `i`, update the `cnt` by:
     - Adding the effect of the new element entering the window (`arr[i]`).
     - Subtracting the effect of the old element that is leaving the window (`arr[i-k]`).
   - If `cnt > 0`, it means there is at least one break in the current window, so append `-1` to the result.
   - If `cnt == 0`, append the last element of the current window (`nums[i]`) to the result.

6. Return the Result:
   - After processing all windows, return the `ans` vector containing the desired output.
*/

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
        vector<int> arr(n, 0);
        int cnt = 0;
        arr[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                arr[i] = 1;
            }
        }
        for (int i = 0; i < k; i++) {
            if (arr[i] == 1) {
                cnt++;
            }
        }
        vector<int> ans;

        if (cnt) {
            ans.push_back(-1);
        } else {
            ans.push_back(nums[k - 1]);
        }
        for (int i = k; i < n; i++) {
            if (arr[i] == 1) { 
                cnt++;
            }
            if (arr[i - k + 1] == 1) {
                cnt--;
            }
            if (cnt) ans.push_back(-1);
            else ans.push_back(nums[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;

    // Call the function
    vector<int> result = sol.resultsArray(nums, k);

    // Output the results
    cout << "Result: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
