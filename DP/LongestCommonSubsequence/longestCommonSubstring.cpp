/*Longest Common Substring

You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string& s1, string& s2, int i, int j) {
    if(i == s1.size() || j == s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i] == s2[j]) {
        return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
    } else {
        return 0;
    }
}

int longestCommonSubstr(string& s1, string& s2) {
    dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));  
    int maxi = 0;
    
    for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                maxi = max(maxi, solve(s1, s2, i, j));
            }
        }
    }
    return maxi;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    
    int result = longestCommonSubstr(s1, s2);
    cout << "Length of longest common substring: " << result << endl;

    return 0;
}
