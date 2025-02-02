#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = low;
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= arr[pivot] && i < high) {
            i++;
        }
        while (j > low && arr[j] > arr[pivot]) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void solve(vector<int> &arr, int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        solve(arr, low, part - 1);
        solve(arr, part + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) { // Change return type to vector<int>
    solve(arr, 0, arr.size() - 1);
    return arr; // Return sorted array
}

int main() {
    vector<int> arr = {4, 2, 6, 9, 3, 7, 1}; // Example input array
    vector<int> sortedArr = quickSort(arr);  // Assign the returned sorted array

    cout << "Sorted array: ";
    for (int num : sortedArr) { // Use sortedArr, not undefined variable
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
