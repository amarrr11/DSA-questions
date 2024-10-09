#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n and arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n and arr[smallest] > arr[right]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        solve(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        solve(arr, n, i);
    }
    return arr;
}

int main() {
    vector<int> arr = {10, 20, 15, 30, 40, 50};

    // Build min-heap
    vector<int> minHeap = buildMinHeap(arr);

    // Print the min-heap
    cout << "Min-Heap: ";
    for (int i = 0; i < minHeap.size(); i++) {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    return 0;
}
