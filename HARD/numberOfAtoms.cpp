/*

726. Number of Atoms

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits 
will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count 
(if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more 
than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (s[i] == ')') {
                unordered_map<string, int> temp = st.top();
                st.pop();
                i++;
                string multi;
                while (i < n && isdigit(s[i])) {
                    multi += s[i];
                    i++;
                }
                if (!multi.empty()) {
                    int mul = stoi(multi);
                    for (auto& it : temp) {
                        temp[it.first] = (it.second) * mul;
                    }
                }
                for (auto& it : temp) {
                    st.top()[it.first] += it.second;
                }
            } else {
                string element;
                element.push_back(s[i]);
                i++;
                while (i < n && isalpha(s[i]) && islower(s[i])) {
                    element.push_back(s[i]);
                    i++;
                }
                string count;
                while (i < n && isdigit(s[i])) {
                    count += s[i];
                    i++;
                }
                if (count.empty()) {
                    st.top()[element] += 1;
                } else {
                    int cnt = stoi(count);
                    st.top()[element] += cnt;
                }
            }
        }
        string ans;
        map<string, int> sorted(st.top().begin(), st.top().end());
        for (auto& it : sorted) {
            ans += it.first;
            int count = it.second;
            if (count > 1) {
                ans += (to_string(count));
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string formula;
    
    // Test case 1
    formula = "H2O";
    cout << "The count of atoms in " << formula << " is: " << solution.countOfAtoms(formula) << endl;
    
    // Test case 2
    formula = "Mg(OH)2";
    cout << "The count of atoms in " << formula << " is: " << solution.countOfAtoms(formula) << endl;
    
    // Test case 3
    formula = "K4(ON(SO3)2)2";
    cout << "The count of atoms in " << formula << " is: " << solution.countOfAtoms(formula) << endl;
    
    // Add more test cases if needed
    
    return 0;
}
