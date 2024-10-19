/*Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 562K+Points: 4
Given an array of integers. Find the Inversion Count in the array.  Two elements arr[i] and arr[j] form an inversion if 
arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array
is already sorted then the inversion count is 0.If an array is sorted in the reverse order then the inversion count is 
the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.*/

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    int index = 0;
    for (int i = low; i <= high; i++) {
        arr[i] = temp[index++];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int inversionCount(vector<int>& arr) {
    cnt = 0;
    mergeSort(arr, 0, arr.size() - 1);
    return cnt;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1}; // Example input array
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int count = inversionCount(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Number of inversions: " << count << endl;

    return 0;
}
