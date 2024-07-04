/*
Non-Decreasing Array

You have been given an integer array/list 'ARR' of size 'N'. Write a solution to check if it could become non-decreasing by
modifying at most 1 element.

We define an array as non-decreasing, if ARR[i] <= ARR[i + 1] holds for every i (0-based) such that (0 <= i <= N - 2).

Sample Input 1 :
2
3
8 4 6
3
8 4 2
Sample Output 1 :
true
false
Explanation to Sample Input 1 :
For Test Case 1 we can have a possible non-decreasing array : 2 4 6
Where only the element at index 0 has been modified.

For Test Case 2 there is no possible way to make the array non-decreasing by modifying at most 1 element.

*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int *arr, int n) {
    bool cnt = false;
    if (n <= 1) return true;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] >= arr[i]) {
            continue;
        }
        if (cnt == true) return false;

        if (i == 0 || arr[i + 1] >= arr[i - 1]) {
            arr[i] = arr[i + 1];
        } else {
            arr[i + 1] = arr[i];
        }
        cnt = true;
    }
    return true;
}

int main() {
    // Example 1
    int arr1[] = {4, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Example 1: " << (isPossible(arr1, n1) ? "True" : "False") << endl;

    // Example 2
    int arr2[] = {4, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Example 2: " << (isPossible(arr2, n2) ? "True" : "False") << endl;

    // Example 3
    int arr3[] = {1, 5, 3, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Example 3: " << (isPossible(arr3, n3) ? "True" : "False") << endl;

    // Example 4
    int arr4[] = {1, 5, 3, 4, 2};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Example 4: " << (isPossible(arr4, n4) ? "True" : "False") << endl;

    return 0;
}
