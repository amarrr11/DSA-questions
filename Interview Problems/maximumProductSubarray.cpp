/*
152. Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

*/
#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
#include <algorithm> // for max

using namespace std;

int maxProduct(vector<int>& nums) {
    double leftProduct = 1, rightProduct = 1;
    int n = nums.size();
    double maxi = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(leftProduct == 0) leftProduct = 1;
        if(rightProduct == 0) rightProduct = 1;

        leftProduct *= nums[i];
        rightProduct *= nums[n - 1 - i];
        
        maxi = max(maxi, max(leftProduct, rightProduct));
    }
    
    return maxi;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers for the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << "Maximum product of a subarray: " << result << endl;

    return 0;
}
