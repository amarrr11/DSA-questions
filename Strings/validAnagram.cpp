/*242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the 
original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(char c:t){
            mp[c]--;
        }
        for(auto &it:mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    string s1 = "anagram";
    string s2 = "nagaram";
    if (solution.isAnagram(s1, s2)) {
        cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are anagrams." << endl;
    } else {
        cout << "Strings \"" << s1 << "\" and \"" << s2 << "\" are not anagrams." << endl;
    }
    
    string s3 = "rat";
    string s4 = "car";
    if (solution.isAnagram(s3, s4)) {
        cout << "Strings \"" << s3 << "\" and \"" << s4 << "\" are anagrams." << endl;
    } else {
        cout << "Strings \"" << s3 << "\" and \"" << s4 << "\" are not anagrams." << endl;
    }

    return 0;
}
