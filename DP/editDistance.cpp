/*72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string &s1, string &s2, int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;

    if (dp[n][m] != -1) return dp[n][m];

    if (s1[n - 1] == s2[m - 1]) {
        return dp[n][m] = solve(s1, s2, n - 1, m - 1);
    } else {
        return dp[n][m] = 1 + min(solve(s1, s2, n - 1, m), 
                                  min(solve(s1, s2, n, m - 1), 
                                      solve(s1, s2, n - 1, m - 1)));
    }
}

int editDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    return solve(s1, s2, n, m);
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int result = editDistance(s1, s2);
    cout << "The Edit Distance between \"" << s1 << "\" and \"" << s2 << "\" is: " << result << endl;

    return 0;
}
