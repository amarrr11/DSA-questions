// 349. Intersection of Two Arrays
// Given two integer arrays nums1 and nums2, return an array of their 
// intersection
// . Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);

                while (i < n - 1 && nums1[i] == nums1[i + 1]) {
                    i++;
                }
                while (j < m - 1 && nums2[j] == nums2[j + 1]) {
                    j++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    std::vector<int> nums1, nums2;
    int n, m;

    std::cout << "Enter the size of the first array: ";
    std::cin >> n;
    std::cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums1.push_back(num);
    }

    std::cout << "Enter the size of the second array: ";
    std::cin >> m;
    std::cout << "Enter the elements of the second array: ";
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        nums2.push_back(num);
    }

    std::vector<int> result = solution.intersection(nums1, nums2);

    std::cout << "Intersection of the two arrays is: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
