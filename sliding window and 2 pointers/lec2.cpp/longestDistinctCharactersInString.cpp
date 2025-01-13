/*Longest substring with distinct characters
Difficulty: EasyAccuracy: 31.32%Submissions: 156K+Points: 2
Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.
Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.
Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.*/

#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

int longestSubstringWithoutRepeatingChars(const string& s) {
    int j = 0;
    int maxi = INT_MIN;
    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); i++) {
        if (mp.find(s[i]) == mp.end() || mp[s[i]] == 0) {
            mp[s[i]]++;
        } else {
            maxi = max(maxi, i - j);
            while (s[j] != s[i]) {
                mp[s[j]]--;
                j++;
            }
            j++;
        }
    }

    maxi = max(maxi, (int)s.size() - j);
    return maxi;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = longestSubstringWithoutRepeatingChars(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
