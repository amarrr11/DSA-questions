// Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Approach
// First keeping i at index 0 and looping from j = 1, then if both elements in i and j are same, increase j+1 , if different values-then first increase ith element by 1 and put put element of j in ith position, then continue the loop .You will understand with the code now


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) // Check if the array is empty
            return 0;
        
        int i = 0; // Index for the non-duplicate elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) { // If current element is different from the previous one
                i++; // Move to the next non-duplicate element
                nums[i] = nums[j]; // Copy the non-duplicate element
            }
        }
        return i + 1; // Return the length of the array with duplicates removed
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int length = solution.removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
