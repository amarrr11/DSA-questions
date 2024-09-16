/*1371. Find the Longest Substring Containing Vowels in Even Counts

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e',
 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels:
 a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(5, 0);  // To track vowel parity
        map<vector<int>, int> mp;
        mp[v] = -1;  // Initialize for empty substring
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // Update the parity for each vowel
            if (s[i] == 'a') {
                v[0] = (v[0] + 1) % 2;
            } else if (s[i] == 'e') {
                v[1] = (v[1] + 1) % 2;
            } else if (s[i] == 'i') {
                v[2] = (v[2] + 1) % 2;
            } else if (s[i] == 'o') {
                v[3] = (v[3] + 1) % 2;
            } else if (s[i] == 'u') {
                v[4] = (v[4] + 1) % 2;
            }

            // Check if this parity has been seen before
            if (mp.find(v) != mp.end()) {
                ans = max(ans, i - mp[v]);
            } else {
                mp[v] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = sol.findTheLongestSubstring(s);
    cout << "The length of the longest substring with all vowels occurring an even number of times is: " << result << endl;
    return 0;
}
