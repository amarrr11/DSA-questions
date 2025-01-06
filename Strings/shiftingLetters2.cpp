/*2381. Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, 
directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if 
directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes
 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping 
 around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);

        for (auto &it : shifts) {
            int start = it[0];
            int end = it[1];
            int dir = it[2];

            diff[start] += (dir == 1 ? 1 : -1);
            if (end + 1 < n) {
                diff[end + 1] -= (dir == 1 ? 1 : -1);
            }
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            diff[i] %= 26;
            if (diff[i] < 0) diff[i] += 26;
            // ans[i] = ((s[i] - 'a') + diff[i]) % 26 + 'a';
            ans.push_back(((s[i] - 'a') + diff[i]) % 26 + 'a');

            // ans.push_back('a' + (s[i] - 'a' + diff[i]) % 26);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "abc";
    vector<vector<int>> shifts1 = {{0, 1, 1}, {1, 2, 0}};
    cout << "Test Case 1: " << endl;
    cout << "Input: " << s1 << endl;
    cout << "Shifts: {{0, 1, 1}, {1, 2, 0}}" << endl;
    cout << "Output: " << sol.shiftingLetters(s1, shifts1) << endl;
    cout << "-----------------------------------" << endl;

    // Example 2
    string s2 = "abcd";
    vector<vector<int>> shifts2 = {{0, 2, 1}, {1, 3, 0}, {0, 3, 1}};
    cout << "Test Case 2: " << endl;
    cout << "Input: " << s2 << endl;
    cout << "Shifts: {{0, 2, 1}, {1, 3, 0}, {0, 3, 1}}" << endl;
    cout << "Output: " << sol.shiftingLetters(s2, shifts2) << endl;
    cout << "-----------------------------------" << endl;

    // Example 3
    string s3 = "zaza";
    vector<vector<int>> shifts3 = {{0, 1, 1}, {1, 3, 1}, {0, 2, 0}};
    cout << "Test Case 3: " << endl;
    cout << "Input: " << s3 << endl;
    cout << "Shifts: {{0, 1, 1}, {1, 3, 1}, {0, 2, 0}}" << endl;
    cout << "Output: " << sol.shiftingLetters(s3, shifts3) << endl;
    cout << "-----------------------------------" << endl;

    // Example 4
    string s4 = "xyz";
    vector<vector<int>> shifts4 = {{0, 2, 1}, {1, 1, 0}};
    cout << "Test Case 4: " << endl;
    cout << "Input: " << s4 << endl;
    cout << "Shifts: {{0, 2, 1}, {1, 1, 0}}" << endl;
    cout << "Output: " << sol.shiftingLetters(s4, shifts4) << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}
