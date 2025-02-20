/*491. Non-decreasing Subsequences

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at 
least two elements. You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int> &nums, vector<int> &temp, int idx) {
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }
        unordered_set<int> s;
        for (int i = idx; i < n; i++) {
            if ((temp.empty() || temp.back() <= nums[i]) && s.find(nums[i]) == s.end()) {
                temp.push_back(nums[i]);
                solve(nums, temp, i + 1);
                temp.pop_back();
            }
            s.insert(nums[i]);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        ans.clear(); // Ensure previous results are cleared
        solve(nums, temp, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> result = solution.findSubsequences(nums);
    
    cout << "Subsequences: \n";
    for (const auto& seq : result) {
        cout << "[ ";
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
