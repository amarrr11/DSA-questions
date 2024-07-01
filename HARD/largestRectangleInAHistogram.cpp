/*
Largest rectangle in a histogram

You have been given an array/list 'HEIGHTS' of length ‘N. 'HEIGHTS' represents the histogram and each element of 'HEIGHTS' 
represents the height of the histogram bar. Consider that the width of each histogram is 1.
You are supposed to return the area of the largest rectangle possible in the given histogram.


*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (s.empty()) {
            left[i] = 0;
        } else {
            left[i] = s.top() + 1;
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (s.empty()) {
            right[i] = n - 1;
        } else {
            right[i] = s.top() - 1;
        }
        s.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int area = heights[i] * (right[i] - left[i] + 1);
        maxi = max(area, maxi);
    }
    return maxi;
}

int main() {
    vector<vector<int>> testCases = {
        {2, 1, 5, 6, 2, 3},
        {6, 2, 5, 4, 5, 1, 6},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 4, 2, 1, 10, 6, 10}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int height : testCases[i]) {
            cout << height << " ";
        }
        cout << "\nLargest Rectangle Area: " << largestRectangle(testCases[i]) << "\n\n";
    }

    return 0;
}
