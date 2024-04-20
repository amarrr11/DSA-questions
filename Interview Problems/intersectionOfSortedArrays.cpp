// Problem statement
// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Note :
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non-decreasing order.
// 3. The output should be in the order of elements that occur in the original arrays.
// 4. If there is no intersection present then return an empty array.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    
    // Input size of array 1
    cout << "Enter the size of array 1: ";
    cin >> n;
    vector<int> arr1(n);
    // Input elements of array 1
    cout << "Enter the elements of array 1: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    // Input size of array 2
    cout << "Enter the size of array 2: ";
    cin >> m;
    vector<int> arr2(m);
    // Input elements of array 2
    cout << "Enter the elements of array 2: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    // Call findArrayIntersection function
    vector<int> intersection = findArrayIntersection(arr1, n, arr2, m);
    
    // Output the intersection
    cout << "Intersection of arrays: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
