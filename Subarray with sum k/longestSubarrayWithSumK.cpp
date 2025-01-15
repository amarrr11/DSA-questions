/*Longest Subarray with Sum K
Difficulty: MediumAccuracy: 24.64%Submissions: 538K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where 
the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest 
subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    long long sum = 0;
    unordered_map<long long, int> mp;
    mp[0] = -1;
    int maxi = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end()) {
            maxi = max(maxi, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end()) { /////////////////////////////////////////////////////
            mp[sum] = i;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // example input
    int k = 5; // target sum
    
    cout << "Length of longest subarray with sum " << k << ": " << longestSubarray(arr, k) << endl;
    
    return 0;
}
