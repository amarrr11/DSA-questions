/*438. Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the 
original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        if (s.size() < n) return {};
        vector<int> ans;

        vector<int> v(26, 0);
        for (char &c : p) {
            v[c - 'a']++;
        }

        vector<int> vec(26, 0);
        for (int i = 0; i < n; i++) {
            vec[s[i] - 'a']++;
        }

        if (vec == v) {
            ans.push_back(0);
        }

        int j = n;
        int i = 0;
        while (j < s.size()) {
            vec[s[j] - 'a']++;
            vec[s[i] - 'a']--;
            i++;

            if (vec == v) {
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";

    // Call the function
    vector<int> result = sol.findAnagrams(s, p);

    // Print the result
    cout << "Anagram indices: ";
    for (int idx : result) {
        cout << idx << " "; 
    }
    cout << endl;

    return 0;
}
