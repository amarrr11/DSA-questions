/*451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the 
number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string str) {
        vector<pair<char, int>> v(123);

        for (auto &c : str) {
            v[c] = {c, v[c].second + 1};
        }

        sort(v.begin(), v.end(), [&](pair<char, int> p1, pair<char, int> p2) {
            return p1.second > p2.second;
        });

        string res = "";
        for (int i = 0; i < 123; i++) {
            if (v[i].second > 0) {
                char c = v[i].first;
                int freq = v[i].second;
                while (freq--) {
                    res += c;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string input = "tree";
    string result = sol.frequencySort(input);
    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
