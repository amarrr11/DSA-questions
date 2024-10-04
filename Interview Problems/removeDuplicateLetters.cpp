/*316. Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.


Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26, 0);
        vector<int> alreadyPresent(26, 0);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            visited[s[i] - 'a'] = i;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (alreadyPresent[s[i] - 'a']) continue;

            while (!st.empty() && s[i] < st.top()) {
                if (visited[st.top() - 'a'] > i) {
                    alreadyPresent[st.top() - 'a'] = false;
                    st.pop();
                } else {
                    break;
                }
            }

            st.push(s[i]);
            alreadyPresent[s[i] - 'a'] = true;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string result = solution.removeDuplicateLetters(input);
    cout << "Result: " << result << endl;

    return 0;
}
