/*
137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the 
single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        //by BIT MANIPULATION TC- O(N*32) and SC-O(1)
        int ans = 0;
        for(int bitIndex = 0; bitIndex < 32; bitIndex++) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] & (1 << bitIndex)) { //if index is set
                    cnt++;
                }
            }
            if(cnt % 3 == 1) {
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;

        //by SORTING AND COMPARING EVERY THIRD ELEMENT : TC=O(NlogN + N/3) SC=O(1)
        
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i += 3) {
            if(nums[i - 1] != nums[i]) 
                return nums[i - 1];
        }
        return nums[n - 1];

        //BY BUCKET METHOD

        int ones = 0, twos = 0;
        
        for(int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~twos ;
            twos = (twos ^ nums[i]) & ~ones ;
        }
        return ones;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2}; // Example input
    int result = sol.singleNumber(nums);
    cout << "The single number is: " << result << endl;
    return 0;
}
