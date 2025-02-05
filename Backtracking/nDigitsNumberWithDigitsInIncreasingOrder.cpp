/*N Digit numbers with digits in increasing order
Difficulty: MediumAccuracy: 49.66%Submissions: 13K+Points: 4
Given an integer n, print all the n digit numbers in increasing order, such that their digits are in strictly increasing 
order(from left to right).

Example 1:

Input:
n = 1
Output:
0 1 2 3 4 5 6 7 8 9
Explanation:
Single digit numbers are considered to be 
strictly increasing order.
Example 2:

Input:
n = 2
Output:
12 13 14 15 16 17 18 19 23....79 89
Explanation:
For n = 2, the correct sequence is
12 13 14 15 16 17 18 19 23 and so on 
up to 89.*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &v, vector<int> &ans) {
    if (n == 0) {
        int a = 0;
        for (int i = 0; i < v.size(); i++) {
            a = a * 10 + v[i];
        }
        ans.push_back(a);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (v.empty() || v.back() < i) {
            v.push_back(i);
            solve(n - 1, v, ans);
            v.pop_back();
        }
    }
}

vector<int> increasingNumbers(int n) {
    vector<int> ans;
    if (n == 1) {
        for (int i = 0; i <= 9; i++) {
            ans.push_back(i);
        }
        return ans;
    }
    vector<int> v;
    solve(n, v, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> result = increasingNumbers(n);
    
    cout << "Increasing numbers of length " << n << ": ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
