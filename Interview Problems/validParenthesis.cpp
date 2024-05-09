// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> ans;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                ans.push_back(s[i]);
            }
            else {
                if(ans.empty()) {
                    return false;
                }
                char c = ans.back();
                ans.pop_back();
                if((s[i] == ']' && c == '[') || (s[i] == '}' && c == '{') || (s[i] == ')' && c == '(')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return ans.empty();
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string containing only parentheses, brackets, and curly braces: ";
    cin >> input;   

    if(sol.isValid(input)) {
        cout << "The string has valid parentheses, brackets, and curly braces." << endl;
    }
    else {
        cout << "The string does not have valid parentheses, brackets, and curly braces." << endl;
    }

    return 0;
}
