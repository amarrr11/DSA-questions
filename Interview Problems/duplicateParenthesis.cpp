/*
 Duplicate Parenthesis

You are given the expression ‘expr’ with parenthesis. Your task is to find if the given expression contains duplicate
parenthesis. A set of parenthesis is duplicate if multiple parenthesis surrounds the same subexpression.
For Example:
You are given ‘expr’ = “(a+b)+((c+d))”, here the subexpression “c+d” is surrounded by two parentheses. Hence the expression 
contains duplicate parenthesis. Hence the answer is “YES”.
*/

/*Intuition:
The problem is to detect whether there are duplicate parentheses in a given string expression. Duplicate parentheses mean that
there exists some redundant pair of parentheses that does not affect the logical structure of the expression. For example, in
the expression "((a+b))", the inner pair of parentheses is redundant.

To solve this problem, we can use a stack data structure. The stack will help us keep track of the parentheses and the
characters between them. When we encounter a closing parenthesis ')', we can check whether it forms a redundant pair with 
the corresponding opening parenthesis '(' by examining the characters between them.

Approach:
Initialize a stack:

We use a stack to keep track of the characters and parentheses as we traverse the string.
Traverse the string:

For each character in the string:
If the character is not a closing parenthesis ')', push it onto the stack.
If the character is a closing parenthesis ')', check for redundancy:
If the top of the stack is an opening parenthesis '(', it means we have found duplicate parentheses, so return true.
Otherwise, pop characters from the stack until we find an opening parenthesis '('. This popping simulates removing the inner
expression enclosed within the parentheses.
After removing the inner expression, pop the opening parenthesis '(' as well.
Return result:

If we complete the traversal without finding any redundant parentheses, return false.*/

#include <bits/stdc++.h>
using namespace std;

bool duplicateParanthesis(string &st) {
    int n = st.size();
    stack<char> s;
    for (int i = 0; i < n; i++) {
        if (st[i] != ')') {
            s.push(st[i]);
        } else {
            if (s.top() == '(') return true;
            while (s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string to check for duplicate parentheses: ";
    getline(cin, input);

    if (duplicateParanthesis(input)) {
        cout << "The string has duplicate parentheses." << endl;
    } else {
        cout << "The string does not have duplicate parentheses." << endl;
    }

    return 0;
}