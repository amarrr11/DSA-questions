#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = arr[s.top()];
        }
        s.push(i);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();
    
    vector<int> result = nextSmallerElement(arr, n);
    
    cout << "Next smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
