/*Add Binary Strings

Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary 
Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to add two binary strings
string addBinary(string& s1, string& s2) {
    int n = s1.size() - 1;
    int m = s2.size() - 1;
    string ans = "";
    int carry = 0;
    
    while (n >= 0 || m >= 0 || carry) {
        int sum = carry;
        if (n >= 0 && s1[n] == '1') sum++;
        if (m >= 0 && s2[m] == '1') sum++;
        
        if (sum == 0) {
            ans += '0';
            carry = 0;
        }
        else if (sum == 1) {
            ans += '1';
            carry = 0;
        }
        else if (sum == 2) {
            ans += '0';
            carry = 1;
        } else {
            ans += '1';
            carry = 1;
        }
        n--;
        m--;
    }
    
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != '0') {
            ans = ans.substr(i);
            break;
        }
    }
    return ans;
}

int main() {
    string s1, s2;
    
    // Input two binary strings
    cout << "Enter first binary string: ";
    cin >> s1;
    cout << "Enter second binary string: ";
    cin >> s2;
    
    // Get the sum of the binary strings
    string result = addBinary(s1, s2);
    
    // Output the result
    cout << "Sum of binary strings: " << result << endl;
    
    return 0;
}
