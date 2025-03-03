/*Longest Bounded-Difference Subarray
Difficulty: MediumAccuracy: 72.93%Submissions: 2K+Points: 4
Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where
 the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.

Examples: 

Input: arr[] = [8, 4, 2, 6, 7], x = 4 
Output: [4, 2, 6] 
Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is
 greater than 4.
Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5 
Output: [2, 4, 7, 2] 
Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements 
which is greater than 5. */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
    map<int, int> mp;  // Stores {element, index}
    vector<int> ans;
    
    int i = 0;  // Start of the window
    for (int j = 0; j < n; j++) {
        mp[arr[j]] = j;  // Insert element and its index
        
        // Get the smallest and largest elements in the current window
        while (!mp.empty() && (mp.rbegin()->first - mp.begin()->first) > x) {
            // Remove the leftmost element from the window
            if (mp[arr[i]] == i) {
                mp.erase(arr[i]);
            }
            i++;
        }
        
        // Update the longest valid subarray
        if (j - i + 1 > ans.size()) {
            ans = vector<int>(arr.begin() + i, arr.begin() + j + 1);
        }
    }
    
    return ans;
}

// Driver function
int main() {
    vector<int> arr = {33, 55, 34, 30, 42, 59, 4, 50, 9, 57, 32, 27, 6, 16, 16, 4, 58, 56, 56, 5};
    int x = 21;
    
    vector<int> result = longestSubarray(arr, x);
    
    cout << "Longest subarray: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
