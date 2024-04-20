// Problem statement
// Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.



// Example:
// 'arr '= [1,2,3,4,5]
// 'k' = 1  rotated array = [2,3,4,5,1]
// 'k' = 2  rotated array = [3,4,5,1,2]
// 'k' = 3  rotated array = [4,5,1,2,3] and so on.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();
    
    // Step 1: Reverse the first k elements of the array
    reverse(arr.begin(), arr.begin() + k);
    
    // Step 2: Reverse the remaining elements of the array
    reverse(arr.begin() + k, arr.end());
    
    // Step 3: Reverse the entire array
    reverse(arr.begin(), arr.end());
    
    // Return the rotated array
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> rotatedArr = rotateArray(arr, k);

    cout << "Array after rotating by " << k << " elements: ";
    for (int num : rotatedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
