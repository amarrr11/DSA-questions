/*
Subarrays with XOR ‘K’

Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise 
XOR( ⊕ ) of all elements is equal to ‘B’.

A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.
Example:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraysWithSumK(vector<int> a, int k) {
    unordered_map<int, int> m;
    int cnt = 0;
    m[0] = 1;
    int xr = 0;
    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];
        if (m.find(xr ^ k) != m.end()) {
            cnt += m[xr ^ k];
        }
        m[xr]++;
    }
    return cnt;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    int result = subarraysWithSumK(a, k);
    cout << "Number of subarrays with XOR sum equal to " << k << " is: " << result << endl;

    return 0;
}
