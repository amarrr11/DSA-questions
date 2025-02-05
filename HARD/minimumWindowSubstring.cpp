/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return
  the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string &s, string &t) {
        int i = 0, j = 0;
        if (s.size() < t.size()) return ""; 
        unordered_map<char, int> mp;
        for (auto &it : t) mp[it]++;

        int ans = INT_MAX;
        string a = "";
        int cnt = 0, start = 0;
        int n = s.size();

        while (i < n && j < n) {
            if (mp[s[j]] > 0) {
                cnt++;
            }
            mp[s[j]]--;
            while (cnt == t.size()) {
                if (ans > j - i + 1) {
                    ans = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }

        return (ans == INT_MAX) ? "" : s.substr(start, ans);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    
    string result = sol.minWindow(s, t);
    cout << "The minimum window substring is: " << result << endl;

    return 0;
}
