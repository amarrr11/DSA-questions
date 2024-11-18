/*Minimum sum partition

Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that 
the absolute difference between their sums is minimum and find the minimum difference.

Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4
Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0
Hence, minimum difference is 1.*/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int sum, int idx) {
    if (sum == 0) {
        return 1;
    }
    if (sum < 0 or idx >= arr.size()) return 0;

    return solve(arr, sum - arr[idx], idx + 1) or solve(arr, sum, idx + 1);
}

int minDifference(vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();

    for (int i = sum / 2; i >= 0; i--) {
        if (solve(arr, i, 0)) {
            return sum - 2 * i;
        }
    }
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 9}; // Example input
    int result = minDifference(arr); // Call to the minDifference function
    cout << "Minimum Difference: " << result << endl; // Output the result
    return 0;
}
