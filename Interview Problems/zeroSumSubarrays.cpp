/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n) {
        map<long long int, long long int> m;
        long long int total = 0;
        long long int sum = 0;

        // Initialize map with sum 0 having count 1 (this handles subarrays starting from index 0).
        m[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Check if current sum has been seen before.
            // If yes, there exists subarrays ending at current index with sum 0.
            if (m.find(sum) != m.end()) {
                total += m[sum];
                m[sum]++;
            } else {
                // If current sum is encountered for the first time, add it to map.
                m[sum] = 1;
            }
        }

        return total;
    }
};

int main() {
    
    Solution sol;

    // Example 1:
    vector<long long int> arr1 = {1, -1, 1, -1, 1};
    int n1 = arr1.size();
    long long int result1 = sol.findSubarray(arr1, n1);
    cout << "Result 1: " << result1 << endl; // Expected output: 4

    // Example 2:
    vector<long long int> arr2 = {1, 2, 3};
    int n2 = arr2.size();
    long long int result2 = sol.findSubarray(arr2, n2);
    cout << "Result 2: " << result2 << endl; // Expected output: 0

    // Example 3:
    vector<long long int> arr3 = {0, 0, 0, 0, 0};
    int n3 = arr3.size();
    long long int result3 = sol.findSubarray(arr3, n3);
    cout << "Result 3: " << result3 << endl; // Expected output: 15

    return 0;
}
