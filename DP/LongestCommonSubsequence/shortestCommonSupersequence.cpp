/*Shortest Common Supersequence

Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
Note: s1 and s2 can have both uppercase and lowercase English letters.

Examples:

Input: s1 = "geek", s2 = "eke"
Output: 5
Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
Input: s1 = "AGGTAB", s2 = "GXTXAYB"
Output: 9
Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
Input: s1 = "geek", s2 = "ek"
Output: 4
Explanation: String "geek" has both string "geek" and "ek" as subsequences.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find length of shortest common supersequence of two strings.
    vector<vector<int>> dp;

    int solve(string &s1, string &s2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }
        if (dp[n - 1][m - 1] != -1) {
            return dp[n - 1][m - 1];
        }
        if (s1[n - 1] == s2[m - 1]) {
            return dp[n - 1][m - 1] = 1 + solve(s1, s2, n - 1, m - 1);
        } else {
            return dp[n - 1][m - 1] = max(solve(s1, s2, n - 1, m), solve(s1, s2, n, m - 1));
        }
    }

    int shortestCommonSupersequence(string &s1, string &s2) {
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        int n = solve(s1, s2, s1.size(), s2.size());
        return s1.size() + s2.size() - n;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Shortest Common Supersequence Length for \"" << s1 << "\" and \"" << s2 << "\": "
         << solution.shortestCommonSupersequence(s1, s2) << endl;

    // Example 2
    s1 = "brute";
    s2 = "groot";
    cout << "Shortest Common Supersequence Length for \"" << s1 << "\" and \"" << s2 << "\": "
         << solution.shortestCommonSupersequence(s1, s2) << endl;

    return 0;
}
