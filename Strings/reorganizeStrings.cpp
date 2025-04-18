/*767. Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> frq(26, 0);
        priority_queue<pair<int, char>> pq;

        for (char &c : s) {
            frq[c - 'a']++;
            if (frq[c - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        for (int i = 0; i < 26; i++) {
            if (frq[i] > 0) {
                pq.push({frq[i], i + 'a'});
            }
        }

        string ans = "";
        while (pq.size() >= 2) {
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();

            ans += first.second;
            ans += second.second;

            if (first.first - 1 > 0) {
                pq.push({first.first - 1, first.second});
            }
            if (second.first - 1 > 0) {
                pq.push({second.first - 1, second.second});
            }
        }

        if (!pq.empty()) {
            ans += pq.top().second;
        }

        return ans;
    }
};
int main() {
    Solution sol;

    vector<string> testCases = {"aab", "aaab", "vvvlo"};

    for (const string& s : testCases) {
        string result = sol.reorganizeString(s);
        cout << "Input: " << s << "\n";
        if (result.empty()) {
            cout << "Output: Reorganization not possible.\n";
        } else {
            cout << "Output: " << result << "\n";
        }
        cout << "------------------------\n";
    }

    return 0;
}
