/*
Next Smaller Element

You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array 
elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly 
smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 
is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            ans[i] = -1;
        }
        while (!s.empty() && arr[i] <= s.top()) {
            s.pop();
        }
        if (arr[i] > s.top() && !s.empty()) {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Additional example
    vector<int> arr2 = {3, 7, 1, 7, 6, 2};
    n = arr2.size();

    vector<int> result2 = nextSmallerElement(arr2, n);

    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Next smaller elements: ";
    for (int i = 0; i < n; ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
