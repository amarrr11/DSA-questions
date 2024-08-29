#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftSmaller(int n, int arr[]) {
        // reverse(arr, arr + n);
        // vector<int> ans(n, -1);
        // stack<int> s;

        // for (int i = n - 1; i >= 0; i--) {
        //     while (!s.empty() && arr[s.top()] >= arr[i]) {
        //         s.pop();
        //     }
        //     if (!s.empty()) {
        //         ans[i] = arr[s.top()];
        //     }
        //     s.push(i);
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;

        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
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
};

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    vector<int> result = sol.leftSmaller(n, arr);

    cout << "Left smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
