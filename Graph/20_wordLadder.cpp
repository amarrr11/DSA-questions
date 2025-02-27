/*127. Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation
 sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) return 0; // If endWord is not in wordList, return 0

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string s = q.front().first;
            int time = q.front().second;
            q.pop();

            for (int i = 0; i < s.size(); i++) {
                char ori = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (st.find(s) != st.end()) {
                        if (s == endWord) return time + 1;
                        q.push({s, time + 1});
                        st.erase(s);
                    }
                }
                s[i] = ori;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
