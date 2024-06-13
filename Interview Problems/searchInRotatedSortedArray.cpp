 /*
33. Search in Rotated Sorted Array
 There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such 
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
 [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1
 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int k = -1;
    int n = nums.size();
    if (n == 0) {
        return -1;
    }
    if (n == 1) {
        return nums[0] == target ? 0 : -1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            k = i;
            // break;
        }
        // else if(nums[n-1]>nums[n-2]){ k=n-1;
        // }
    }

    int low = 0;
    int high = k;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
        // mid=(high+low)/2;
    }

    low = k + 1;
    high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
        // mid=(high+low)/2;
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(nums, target);
    cout << "Index of " << target << " in the array: " << result << endl;

    target = 3;
    result = search(nums, target);
    cout << "Index of " << target << " in the array: " << result << endl;

    return 0;
}
