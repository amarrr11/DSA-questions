// 80. Remove Duplicates from Sorted Array II
// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element 
//appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in 
//the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k
 //elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.
// Example 1:

// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int in = 2;
        if (nums.size() < 3) {
            return nums.size();
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[in - 2]) {
                nums[in] = nums[i];
                in++;
            }
        }
        return in;
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break; // break if newline is encountered
    }

    int k = solution.removeDuplicates(nums);
    cout << k << ", nums = [";
    for (int i = 0; i < k; ++i) {
        cout << nums[i];
        if (i != k - 1) cout << ", ";
    }
    for (int i = k; i < nums.size(); ++i) {
        cout << ",_";
    }
    cout << "]" << endl;

    return 0;
}
