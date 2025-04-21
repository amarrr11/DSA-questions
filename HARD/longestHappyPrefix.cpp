/*1392. Longest Happy Prefix

A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[s.size() - 1];
    }

    string longestPrefix(string s) {
        int lps = solve(s);
        if (lps == 0) return "";
        return s.substr(0, lps);
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "level";
    cout << "Longest prefix which is also suffix of \"" << s1 << "\": " << sol.longestPrefix(s1) << endl;

    // Example 2
    string s2 = "ababab";
    cout << "Longest prefix which is also suffix of \"" << s2 << "\": " << sol.longestPrefix(s2) << endl;

    // Example 3
    string s3 = "leetcode";
    cout << "Longest prefix which is also suffix of \"" << s3 << "\": " << sol.longestPrefix(s3) << endl;

    return 0;
}
