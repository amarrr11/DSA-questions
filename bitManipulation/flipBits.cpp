/*
 Flip Bits

You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits
of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.
A flip operation is one in which you turn 1 into 0 and 0 into 1.

For example:
If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping 
anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits.
So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.
*/

#include <bits/stdc++.h>
using namespace std;

int flipBits(int* arr, int n) {
    int sum = 0, maxi = INT_MIN, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            sum -= 1;
        } else {
            sum += 1;
        }
        if(sum < 0) {
            sum = 0;
        }
        maxi = max(maxi, sum);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1)
            cnt++;
    }
    return cnt + maxi;
}

int main() {
    // Example 1
    int arr1[] = {1, 0, 0, 1, 0};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Result for Example 1: " << flipBits(arr1, n1) << endl;

    // Example 2
    int arr2[] = {1, 1, 0, 0, 1, 0, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Result for Example 2: " << flipBits(arr2, n2) << endl;

    // Example 3
    int arr3[] = {0, 0, 0, 1, 1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout << "Result for Example 3: " << flipBits(arr3, n3) << endl;

    return 0;
}
