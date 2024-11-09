/*1155. Number of Dice Rolls With Target Sum

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so
 the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;

class Solution {
public:
    vector<vector<ll>> dp;

    ll solve(int n, int k, int t) {
        if (n == 0 && t == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][t] != -1) return dp[n][t];

        ll sum = 0;
        for (int i = 1; i <= k; i++) {
            if (t - i < 0) continue;
            sum = (sum + solve(n - 1, k, t - i)) % mod;
        }

        return dp[n][t] = sum;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(105, vector<ll>(1005, -1));
        return solve(n, k, target);
    }
};

int main() {
    Solution solution;
    int n, k, target;

    // Sample input
    cout << "Enter number of dice (n): ";
    cin >> n;
    cout << "Enter number of faces on each die (k): ";
    cin >> k;
    cout << "Enter target sum: ";
    cin >> target;

    int result = solution.numRollsToTarget(n, k, target);
    cout << "Number of ways to achieve target sum: " << result << endl;

    return 0;
}
