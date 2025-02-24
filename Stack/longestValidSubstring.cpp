/*Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 145K+Points: 8Average Time: 20m
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis
 substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
Examples :

Input: s = "((()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Input: s = ")()())"
Output: 4
Explanation: The longest valid parenthesis substring is "()()".
Input: s = "())()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".*/

#include <bits/stdc++.h>
using namespace std;

int maxLength(string& s) {
    stack<int> st;
    st.push(-1);
    int maxi = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            }
            maxi = max(maxi, i - st.top());
        }
    }
    return maxi;
}

int main() {
    string s;
    cout << "Enter a string containing '(' and ')': ";
    cin >> s;
    
    int result = maxLength(s);
    cout << "Longest valid parentheses length: " << result << endl;
    
    return 0;
}
