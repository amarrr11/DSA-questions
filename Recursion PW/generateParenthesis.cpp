/*22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

//kbhi v close open se jyda nh hoga...

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int n, vector<string>& ans, string temp, int open, int close) {

        if (close > open || open > n || close > n) {
            return;
        }
        if (open == close && open == n) {
            ans.push_back(temp);
            return;
        }

        solve(n, ans, temp + '(', open + 1, close);
        solve(n, ans, temp + ')', open, close + 1);
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, ans, "", 0, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 3;  // Example input for generating parentheses

    vector<string> result = solution.generateParenthesis(n);

    cout << "All combinations of " << n << " pairs of parentheses:\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}
