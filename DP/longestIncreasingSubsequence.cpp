/*300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing 
subsequence


Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;
    int solve(vector<int> &nums,int idx,int prev){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int exclude=0+solve(nums,idx+1,prev);
        int include=0;
        if(prev==-1 or nums[idx]>nums[prev]){
            include= 1+ solve(nums,idx+1,idx);
        }
        return dp[idx][prev+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1);
    }
};
int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input array
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Find the length of the longest increasing subsequence
    int result = solution.lengthOfLIS(nums);

    // Output the result
    cout << "Length of the Longest Increasing Subsequence: " << result << endl;

    return 0;
}