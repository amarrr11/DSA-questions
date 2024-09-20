/*Longest Prefix Suffix
Difficulty: Hard
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lps(string str) {
        vector<int> lps(str.size(), 0);
        int suf = 1, pre = 0;
        while (suf < str.size()) {
            if (str[pre] == str[suf]) {
                lps[suf] = pre + 1;
                pre++, suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[str.size() - 1];
    }
};

int main() {
    Solution sol;
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int result = sol.lps(str);
    cout << "The length of the longest proper prefix which is also a suffix is: " << result << endl;
    return 0;
}
