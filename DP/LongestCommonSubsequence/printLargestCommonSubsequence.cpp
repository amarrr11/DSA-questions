#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2) {
    string ans = "";
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;

    // Trace back the LCS
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());  // Reverse the result to get the LCS in correct order
    return ans;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    int n = s1.length();
    int m = s2.length();

    string lcs = findLCS(n, m, s1, s2);

    cout << "The Longest Common Subsequence is: " << lcs << endl;

    return 0;
}
