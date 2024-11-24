/*Minimum number of deletions and insertions

Given two strings s1 and s2. The task is to remove or insert the minimum number of characters from/in s1 to transform it 
into s2. It could be possible that the same character needs to be removed from one point of s1 and inserted into another
 point.

Examples :

Input: s1 = "heap", s2 = "pea"
Output: 3
Explanation: 'p' and 'h' deleted from heap. Then, 'p' is inserted at the beginning.
Input : s1 = "geeksforgeeks", s2 = "geeks"
Output: 8
Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(string &s1, string &s2, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    if (dp[n - 1][m - 1] != -1) return dp[n - 1][m - 1];
    if (s1[n - 1] == s2[m - 1]) {
        return dp[n - 1][m - 1] = 1 + solve(s1, s2, n - 1, m - 1);
    } else {
        return dp[n - 1][m - 1] = max(solve(s1, s2, n - 1, m), solve(s1, s2, n, m - 1));
    }
}

int minOperations(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    int ans = solve(s1, s2, n, m);
    return n + m - (2 * ans);
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int result = minOperations(s1, s2);
    cout << "The minimum number of operations to make the strings equal is: " << result << endl;

    return 0;
}
