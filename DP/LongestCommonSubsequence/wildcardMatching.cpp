/*44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j) {
        if (i < 0 and j < 0) return true;
        if (i >= 0 and j < 0) return false;
        if (i < 0 and j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j]) {
            return dp[i][j] = solve(s, p, i - 1, j - 1);
        } else if (p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1);
        } else if (p[j] == '*') {
            return dp[i][j] = solve(s, p, i - 1, j) || solve(s, p, i, j - 1);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string txt, string pat) {
        dp.clear();
        dp.resize(txt.size() + 1, vector<int>(pat.size() + 1, -1));
        return solve(txt, pat, txt.size() - 1, pat.size() - 1);
    }
};

int main() {
    Solution solution;
    string txt, pat;

    cout << "Enter the text: ";
    cin >> txt;

    cout << "Enter the pattern: ";
    cin >> pat;

    if (solution.isMatch(txt, pat)) {
        cout << "Match found!" << endl;
    } else {
        cout << "No match!" << endl;
    }

    return 0;
}
