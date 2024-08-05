/*2134. Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array 
together at any location.

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.*/


#include <iostream>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        vector<int> v(2*n);

        for(int i=0; i<2*n; i++) {
            v[i] = nums[i%n];
        }

        int totalOnes = accumulate(begin(nums), end(nums), 0);

        int i=0, j=0, sum=0, maxi=0;
        while(j < 2*n) {
            sum += v[j];

            if(j - i + 1 > totalOnes) {
                sum -= v[i];
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        }
        return totalOnes - maxi;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 0, 1, 0, 1};
    cout << "Example 1: " << solution.minSwaps(nums1) << endl;  // Output: 1

    // Example 2
    vector<int> nums2 = {1, 1, 0, 0, 1};
    cout << "Example 2: " << solution.minSwaps(nums2) << endl;  // Output: 1

    // Example 3
    vector<int> nums3 = {0, 0, 0, 1, 0};
    cout << "Example 3: " << solution.minSwaps(nums3) << endl;  // Output: 0

    return 0;
}
