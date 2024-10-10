/*Kth Smallest
Difficulty: Medium
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest 
element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    // Max heap to store the k smallest elements
    priority_queue<int> pq;

    // Insert first k elements into the max heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // The top element of the max heap is the k-th smallest element
    return pq.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "K-th smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}
