/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0, maxi = 0;
    
    while (second < s.size()) {
        if (count[s[second]] == 0) {
            count[s[second]] = 1;
            len = second - first + 1;
            maxi = max(maxi, len);
            second++;
        } else {
            if (count[s[first]] != 0) {
                count[s[first]] = 0;
                first++;
            }
        }
    }
    return maxi;
}

int main() {
    vector<string> test_cases = {
        "",
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "au",
        "dvdf"
    };

    for (const string& test : test_cases) {
        cout << "Input: \"" << test << "\" -> Output: " << lengthOfLongestSubstring(test) << endl;
    }

    return 0;
}
