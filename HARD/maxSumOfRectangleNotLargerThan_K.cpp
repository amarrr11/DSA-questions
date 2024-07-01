/*
363. Max Sum of Rectangle No Larger Than K

Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no 
larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int kadane(vector<int> &arr, int k) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = 0;
            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];
                if (sum <= k) {
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }

    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int maxi = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for (int left_col = 0; left_col < m; left_col++) {
            vector<int> temp(n, 0);
            for (int i = left_col; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    temp[j] += (mat[j][i]);
                }
                int sum = kadane(temp, k);
                maxi = max(sum, maxi);
                if (maxi == k) return maxi;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 0, 1},
        {0, -2, 3}
    };
    int k = 2;
    int result = sol.maxSumSubmatrix(mat, k);
    cout << "Maximum sum of submatrix no larger than " << k << " is: " << result << endl;
    return 0;
}
