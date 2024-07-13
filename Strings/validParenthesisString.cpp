/*678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;
        stack<int> s2;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*')
                s2.push(i);
            else if (s[i] == '(')
                s1.push(i);
            else {
                if (!s1.empty() && s[s1.top()] == '(')
                    s1.pop();
                else if (!s2.empty() && s[s2.top()] == '*')
                    s2.pop();
                else
                    return false;
            }
        }
        //The basic idea is ki ya to (  rhega ya fir * . and ( ke baad hi * ya ) aana chahiye. hence yahi check krna hai ki
        // ( pehle aaye uske baad * aaye.
        
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() > s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return s1.empty();
    }
};

int main() {
    Solution solution;

    // Example 1: Valid string
    string s1 = "(*))";
    cout << "Is '" << s1 << "' valid? " << (solution.checkValidString(s1) ? "Yes" : "No") << endl;

    // Example 2: Invalid string
    string s2 = "(*)";
    cout << "Is '" << s2 << "' valid? " << (solution.checkValidString(s2) ? "Yes" : "No") << endl;

    // Example 3: Valid string
    string s3 = "((*)";
    cout << "Is '" << s3 << "' valid? " << (solution.checkValidString(s3) ? "Yes" : "No") << endl;

    // Example 4: Invalid string
    string s4 = ")*(";
    cout << "Is '" << s4 << "' valid? " << (solution.checkValidString(s4) ? "Yes" : "No") << endl;

    return 0;
}
