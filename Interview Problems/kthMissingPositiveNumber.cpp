/*1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int j = arr.size() - 1;

        // If the last element of the array is in its expected position
        if (arr[j] == j + 1) {
            return arr[j] + k;
        }

        // If the k-th missing element is before the first element
        if (arr[i] > k) {
            return k;
        }

        // Binary search to find the position where k-th missing element would be
        while (i <= j) {
            int mid = i + (j - i) / 2;
            int ele = mid + 1;

            if ((arr[mid] - ele) < k) { // find how many elements are ignored
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        int a = k - (arr[j] - j - 1); // find how many elements were ignored beforehand.(7-4) 3 were ignored
        return arr[j] + a; // 7 + (k-3)
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "-th missing positive number is: " << result << endl;

    /*for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= k) {
            k++;
        } else {
            break;
        }
    }
    return k;*/
    
    return 0;
}
