/*Nearly sorted

Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.

Note: DO NOT use STL sort() function for this question.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push the first k+1 elements into the priority queue
        for(int i = 0; i <= k && i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        
        int index = 0;
        
        // Process the rest of the elements in the array
        for(int i = k + 1; i < arr.size(); i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        // Empty the remaining elements in the priority queue into the array
        while(!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};

int main() {
    // Test data
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    // Creating an instance of Solution
    Solution sol;
    
    // Before sorting
    cout << "Original array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    // Apply the nearlySorted function
    sol.nearlySorted(arr, k);
    
    // After sorting
    cout << "Sorted array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

