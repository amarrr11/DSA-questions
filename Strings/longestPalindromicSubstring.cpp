/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

bool solve(int i, int j, string& s) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalinSubstring(string s) {
    int n = s.size();
    int maxi = INT_MIN;
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (solve(i, j, s)) {
                int len = j - i + 1;
                if (len > maxi) {
                    maxi = len;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxi);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalinSubstring(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
