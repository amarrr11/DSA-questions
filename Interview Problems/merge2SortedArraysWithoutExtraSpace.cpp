/*Merge Two Sorted Arrays Without Extra Space

Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.



You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements,
array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.

Sample Input 1:
3 4
1 8 8
2 3 4 5
Sample Output 1:
1 2 3 4 5 8 8

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b) {
    int aLen = a.size();
    int bLen = b.size();
    int left = aLen - 1;
    int right = 0;

    while (left >= 0 && right < bLen) {
        if (a[left] > b[right]) {
            swap(a[left], b[right]);
            left--;
            right++;
        } else {
            // already sorted
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<long long> a = {1, 3, 5, 7};
    vector<long long> b = {2, 4, 6, 8};

    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    cout << "Array a: ";
    for (long long x : a) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Array b: ";
    for (long long x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
