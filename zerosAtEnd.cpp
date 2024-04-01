// Problem statement
// Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping the non-zero elements at the start of the array in their original order. Return the modified array.



// Example :
// Input: ‘n’ = 5, ‘arr’ = [1, 2, 0, 0, 2, 3]
// Output: [1, 2, 2, 3, 0, 0]

// Explanation: Moved all the 0’s to the end of an array, and the rest of the elements retain the order at the start.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    for(int i = 0, j = 0; i < n; i++) {
        if(a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> movedArr = moveZeros(arr.size(), arr);

    cout << "Array after moving zeros to the end: ";
    for (int num : movedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
