/*Largest subarray of 0's and 1's
Difficulty: EasyAccuracy: 32.96%Submissions: 92K+Points: 2
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with equal 0s and 1s
int longestSubarrayWithEqual01(vector<int>& arr) {
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = -1; // To handle cases where the entire array is balanced
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1)
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            maxi = max(maxi, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1}; // Example input array
    int result = longestSubarrayWithEqual01(arr);
    cout << "Length of the longest subarray with equal 0s and 1s: " << result << endl;
    return 0;
}
