/*Count all triplets with given sum in sorted array

Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that 
arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Two triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1. */

#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i <= n - 3; i++) {
        int start = i + 1;
        int end = n - 1;
        while (start < end) {
            if (arr[i] + arr[start] + arr[end] == target) {
                cnt++;
                // break;
                int temp = start + 1;
                while (temp < end && arr[temp] == arr[temp - 1]) {
                    cnt++;
                    temp++;
                }
                end--;
                // }
            }
            else if (arr[i] + arr[start] + arr[end] > target) {
                end--;
            }
            else {
                start++;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 10;
    
    int result = countTriplets(arr, target);
    cout << "Number of triplets: " << result << endl;
    
    return 0;
}
