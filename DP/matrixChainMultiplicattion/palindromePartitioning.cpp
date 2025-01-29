/*132. Palindrome Partitioning II

Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> isPalindromeMemo;

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true; // Base case: single character or empty string
        if (isPalindromeMemo[i][j] != -1) return isPalindromeMemo[i][j];

        if (s[i] != s[j]) {
            isPalindromeMemo[i][j] = 0; // Not a palindrome
            return false;
        }

        // Recursively check for the inner substring
        isPalindromeMemo[i][j] = isPalindrome(s, i + 1, j - 1);
        return isPalindromeMemo[i][j];
    }

    int solve(string &s, int i, int j) {
        if (i > j) return 0;

        if (isPalindrome(s, i, j)) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;

        for (int k = i; k <= j - 1; k++) {
            int left, right;
            if (dp[i][k] != -1) {
                left = dp[i][k];
            } else {
                left = solve(s, i, k);
            }
            if (dp[k + 1][j] != -1) {
                right = dp[k + 1][j];
            } else {
                right = solve(s, k + 1, j);
            }

            int temp = 1 + left + right;
            mini = min(mini, temp);
        }

        return dp[i][j] = mini;
    }

    int minCut(string s) {
        dp.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
        isPalindromeMemo.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(s, 0, s.size() - 1);
    }
};

int main() {
    Solution sol;
    
    string s = "aab";
    int result = sol.minCut(s);
    
    cout << "Minimum cuts required for string \"" << s << "\": " << result << endl;
    
    return 0;
}
