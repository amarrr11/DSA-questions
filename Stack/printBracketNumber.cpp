/*Print Bracket Number

Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the 
ith opening or closing bracket to appear in the string. 

Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        int size = 0;
        vector<int> v;
        stack<int> s;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(') {
                size++;
                s.push(size);
                v.push_back(s.top());
            } else if(str[i] == ')') {
                v.push_back(s.top());
                s.pop();
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    string str = "(a+b)*(c+d)";
    vector<int> result = sol.bracketNumbers(str);

    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
