/*1190. Reverse Substrings Between Each Pair of Parentheses

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string str) {
        stack<int> s;
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                s.push(i);
            } else if (str[i] == ')') {
                reverse(str.begin() + s.top() + 1, str.begin() + i);
                s.pop();
            }
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == ')') {
                continue;
            } else {
                ans += str[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string input = "(u(love)i)";
    string output = solution.reverseParentheses(input);
    cout << "Output: " << output << endl; // Expected output: "iloveu"

    return 0;
}
