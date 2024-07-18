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
Output: [[],[0]]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, int n, vector<int>& temp) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, nums, n, temp);
        temp.pop_back();
        solve(i + 1, nums, n, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, nums.size(), temp);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.subsets(nums);

    // Print the subsets
    cout << "Subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
