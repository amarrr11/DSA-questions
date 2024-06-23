/*
435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to
remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1]; // Sort by ending time
            } else {
                return a[0] < b[0]; // If ending times are the same, sort by starting time
            }
        });
        int cnt = 1;
        int end = nums[0][1];
        for (int i = 1; i < n; i++) {
            if (nums[i][0] >= end) {
                end = nums[i][1];
                cnt++;
            } else {
                continue;
            }
        }
        return (n - cnt);
    }
};

int main() {
    // Example input: [[1,2], [2,3], [3,4], [1,3]]
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    
    Solution sol;
    int result = sol.eraseOverlapIntervals(intervals);
    
    cout << "Number of intervals to remove: " << result << endl;

    return 0;
}
