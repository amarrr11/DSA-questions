/*Longest Repeating Subsequence
Difficulty: MediumAccuracy: 48.54%Submissions: 134K+Points: 4
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has 
different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the
 original string for A and B.

Examples :

Input: s = "axxzxy"
Output: 2
Explanation: The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5
The longest subsequence is "xx". It appears twice as explained below.
subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of s
subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of s
We are able to use character 'x' (at index 2 in s) in both subsequences as it appears on index 1 in subsequence A and index
 0 in subsequence B.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Declare the dp array
vector<vector<int>> dp;

// Recursive solve function
int solve(string &s1, string &s2, int i, int j) {
    if (i >= s1.size() || j >= s2.size()) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (i != j && s1[i] == s2[j]) {
        return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
    } else {
        return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
}

// Function to find the longest repeating subsequence
int LongestRepeatingSubsequence(string &s) {
    dp.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
    return solve(s, s, 0, 0);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = LongestRepeatingSubsequence(s);
    cout << "The length of the longest repeating subsequence is: " << result << endl;

    return 0;
}