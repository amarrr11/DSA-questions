/*Sub-arrays with equal number of occurences
Difficulty: HardAccuracy: 57.94%Submissions: 11K+Points: 8
Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is
equal to the number of occurrences of y.

Examples:

Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).
Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).
Input: arr[] = [1, 2, 1] , x= 1 , y = 4
Output: 1
Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int countx = 0;
        int county = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                countx++;
            }
            if (arr[i] == y) {
                county++;
            }
            if (mp[countx - county]) {
                cnt += mp[countx - county];
            }
            mp[countx - county]++;
        }
        return cnt;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 2, 3, 1, 2};
    int x = 2, y = 3;
    Solution solution;
    int result = solution.sameOccurrence(arr, x, y);
    cout << "Number of subarrays with same occurrences of " << x << " and " << y << ": " << result << endl;
    return 0;
}