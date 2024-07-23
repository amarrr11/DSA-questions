/*
Minimum Sum of Absolute Differences

You have been given two arrays/lists 'ARR1' and 'ARR2' of length 'N'. Your task is to pair each element of 'ARR1' to an 
element of 'ARR2' such that the sum of the absolute difference of all pairs is minimum.

Example:
If 'ARR1' = [0, 2, 1], and 'ARR2' = [8, 10, 4] then the most optimal pairing will be (0, 4) , (1, 8) and (2, 10). The sum 
of absolute difference will be 4 + 7 + 8 = 19.
Note:
An element from one array can make a pair only with at most one element of another array.
*/

//approach: simple sort both and will get the min sum;

#include <bits/stdc++.h>
using namespace std;

int minimumSum(vector<int>& arr1, vector<int>& arr2, int n) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(arr1[i] - arr2[i]);
    }
    return sum;
}

int main() {
    // Sample input
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 3, 4};
    int n = arr1.size();

    // Function call
    int result = minimumSum(arr1, arr2, n);

    // Output result
    cout << "Minimum sum of absolute differences: " << result << endl;

    return 0;
}
