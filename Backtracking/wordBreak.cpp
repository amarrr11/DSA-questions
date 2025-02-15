/*139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of
 one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> t;
    unordered_set<string> st;
    
    bool solve(int idx, string &s) {
        if (idx == s.size()) return true;
        if (t[idx] != -1) return t[idx];
        
        for (int len = 1; len <= s.size() - idx; len++) {
            string temp = s.substr(idx, len);
            if (st.find(temp) != st.end() && solve(idx + len, s)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        t.clear();
        t.resize(s.size() + 1, -1);
        st.clear();
        
        for (auto &w : wordDict) {
            st.insert(w);
        }
        return solve(0, s);
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    if (sol.wordBreak(s, wordDict)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
