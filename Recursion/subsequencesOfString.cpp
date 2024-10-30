/* Subsequences of String

Problem statement
You are given a string 'STR' containing lowercase English letters from a to z inclusive. Your task is to find all non-empty 
possible subsequences of 'STR'.

A Subsequence of a string is the one which is generated by deleting 0 or more letters from the string and keeping the rest of 
the letters in the same order.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int i, vector<string> &ans, string &temp) {
    int n = s.size();
    if (i == n) {
        ans.push_back(temp);
        
        return;
    }

    temp.push_back(s[i]);
    solve(s, i + 1, ans, temp);
    temp.pop_back();
    solve(s, i + 1, ans, temp);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string temp = "";
    solve(str, 0, ans, temp);
    return ans;
}

int main() {
    string str = "abc";
    vector<string> result = subsequences(str);

    // Print the subsequences
    cout << "Subsequences are:" << endl;
    for (const auto &subseq : result) {
        cout << subseq << endl;
    }

    return 0;
}
