/*
31. Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2],
[3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement
is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
        return nums;
    }
};

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> result1 = solution.nextPermutation(nums1);
    printVector(result1);

    // Example 2
    vector<int> nums2 = {3, 2, 1};
    vector<int> result2 = solution.nextPermutation(nums2);
    printVector(result2);

    // Example 3
    vector<int> nums3 = {1, 1, 5};
    vector<int> result3 = solution.nextPermutation(nums3);
    printVector(result3);

    // Example 4
    vector<int> nums4 = {1, 3, 2};
    vector<int> result4 = solution.nextPermutation(nums4);
    printVector(result4);

    // Example 5
    vector<int> nums5 = {2, 3, 1};
    vector<int> result5 = solution.nextPermutation(nums5);
    printVector(result5);

    return 0;
}
