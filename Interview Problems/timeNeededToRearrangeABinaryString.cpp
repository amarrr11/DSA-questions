/*
2380. Time Needed to Rearrange a Binary String

You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process 
repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.


Example 1:

Input: s = "0110101"
Output: 4
Explanation: 
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.
Example 2:

Input: s = "11100"
Output: 0
Explanation:
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.*/

#include <iostream>
#include <string>
using namespace std;

int secondsToRemoveOccurrences(string s) {
    int n = s.size();
    int ans = 0;
    while (true) {
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                swap(s[i], s[i + 1]);
                flag = true;
                i++;
            }
        }
        if (flag) ans++;
        else break;
    }
    return ans;
}

int main() {
    // Example 1
    string s1 = "0110101";
    int result1 = secondsToRemoveOccurrences(s1);
    cout << "Seconds to remove occurrences in \"" << s1 << "\": " << result1 << endl;

    // Example 2
    string s2 = "110";
    int result2 = secondsToRemoveOccurrences(s2);
    cout << "Seconds to remove occurrences in \"" << s2 << "\": " << result2 << endl;

    // Example 3
    string s3 = "0011";
    int result3 = secondsToRemoveOccurrences(s3);
    cout << "Seconds to remove occurrences in \"" << s3 << "\": " << result3 << endl;

    return 0;
}
