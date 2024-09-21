/*28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is 
not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findLps(vector<int> &lps, string s) {
        int i = 0;
        int j = 1;
        while (j < s.size()) {
            if (s[i] == s[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0) {
                    j++;
                } else {
                    i = lps[i - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        findLps(lps, needle);
        int i = 0, j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
            if (j == needle.size()) {
                return (i - j);
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int result = sol.strStr(haystack, needle);
    cout << "The position of the first occurrence of needle in haystack: " << result << endl;
    return 0;
}
