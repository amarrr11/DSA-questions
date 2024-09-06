/*The Celebrity Problem
Difficulty: Medium
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  
A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it 
means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not 
exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0],
                [0 0 0], 
                [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
Input: mat[][] = [[0 1],
                [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            s.push(i);
        }
        while (s.size() > 1) {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();

            if (mat[first][second] && !mat[second][first]) { //first one know second but second dont know him
                s.push(second);
            } else if (!mat[first][second] && mat[second][first]) { //second knows first but not first
                s.push(first);
            } //if they both know each other cant be celebrity o
            //if both dont know each other cant be celibrty
        }
        if (s.empty()) return -1;  
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[s.top()][i]; //sum of rows must be zero
        }
        if (sum != 0) return -1;
        sum = 0;
        for (int i = 0; i < n; i++) { //sum of cols must be n-1
            sum += mat[i][s.top()];
        }
        if (sum != n - 1) return -1;
        return s.top();
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution sol;
    int result = sol.celebrity(mat);
    if (result == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is at index: " << result << endl;
    }

    return 0;
}
