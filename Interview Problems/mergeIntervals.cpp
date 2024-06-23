/*
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the
non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = nums[i][0];
            int end = nums[i][1];
            if (!ans.empty() && ans.back()[1] >= end) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (nums[j][0] <= end) {
                    end = max(end, nums[j][1]);
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = solution.merge(intervals);

    cout << "Merged intervals:" << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}
