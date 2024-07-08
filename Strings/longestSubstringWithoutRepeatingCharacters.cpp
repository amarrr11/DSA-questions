/*
Longest Substring Without Repeating Characters

Given a string input of length n, find the length of the longest substring without repeating characters i.e return a 
substring that does not have any repeating characters.

Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

Sample Input 1:
abcabcbb 
Sample Output1:
 3
Explanation For Sample Input 1:
Substring "abc" has no repeating character with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string s)
{
    int n = s.size();
    int maxi = 0;

    vector<bool> count(256, 0);
    int first = 0, second = 0;
    while (second < n) {
        while (count[s[second]]) {
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        int len = second - first + 1;
        maxi = max(maxi, len);
        second++;
    }
    return maxi;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    
    cout << "The length of the longest substring without repeating characters in \"" << s1 << "\" is " << uniqueSubstrings(s1) << endl;
    cout << "The length of the longest substring without repeating characters in \"" << s2 << "\" is " << uniqueSubstrings(s2) << endl;

    return 0;
}
