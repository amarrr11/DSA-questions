/*516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing 
the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    // int solve(string s1,string s2,int n,int m){
    //     if(n==0 or m==0){
    //         return 0;
    //     }
    //     if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
    //     if(s1[n-1]==s2[m-1]){
    //         return dp[n-1][m-1]= 1+solve(s1,s2,n-1,m-1);
    //     }else{
    //         return dp[n-1][m-1]=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
    //     }
    // }
    int solve(string s1, string s2, int n, int m) {
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s1) {
        reverse(s1.begin(), s1.end());
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        int n = s1.size();
        int m = s2.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(s1, s2, n, m);
    }
};

int main() {
    Solution solution;
    string s = "bbbab";
    cout << "The length of the longest palindromic subsequence is: " << solution.longestPalindromeSubseq(s) << endl;
    return 0;
}
