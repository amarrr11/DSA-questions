/*
3223. Minimum Length of String After Operations

You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and 
at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.

 

Example 1:

Input: s = "abaacbcbb"

Output: 5

Explanation:
We do the following operations:

Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
Example 2:

Input: s = "aa"

Output: 2

Explanation:
We cannot perform any operations, so we return the length of the original string.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char c : s) {
            mp[c]++;
        } 
     
        int sum = 0;
        for(auto& i : mp) {
            while(i.second >= 3) {
                i.second -= 2;
            }
            sum += i.second;
        }
        return sum;
    }
};

int main() {
    Solution sol;

    string s1 = "aabccc";
    string s2 = "aaaa";
    string s3 = "abc";
    string s4 = "aabbcc";
    string s5 = "aabbccc";

    cout << "Minimum length for \"" << s1 << "\": " << sol.minimumLength(s1) << endl; // Output: 2
    cout << "Minimum length for \"" << s2 << "\": " << sol.minimumLength(s2) << endl; // Output: 2
    cout << "Minimum length for \"" << s3 << "\": " << sol.minimumLength(s3) << endl; // Output: 3
    cout << "Minimum length for \"" << s4 << "\": " << sol.minimumLength(s4) << endl; // Output: 6
    cout << "Minimum length for \"" << s5 << "\": " << sol.minimumLength(s5) << endl; // Output: 3

    return 0;
}
