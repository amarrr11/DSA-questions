/*78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, vector<int> temp) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
            
        // Exclude current element
        solve(i + 1, nums, temp);
        
        // Include current element
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Example input

    vector<vector<int>> result = sol.subsets(nums);

    // Print the result
    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
