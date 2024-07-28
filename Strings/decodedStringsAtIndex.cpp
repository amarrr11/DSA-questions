/*880. Decoded String at Index

You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time 
and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

 

Example 1:

Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
Example 2:

Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".
Example 3:

Input: s = "a2345678999999999999999", k = 1
Output: "a"
Explanation: The decoded string is "a" repeated 8301530446056247680 times.
The 1st letter is "a".*/

#include <iostream>
#include <string>
using namespace std;

char kThCharaterOfDecryptedString(string s, long long k) {
    string str = "";
    long long i = 0;
    long long n = s.size();
    long long len = 0;

    while (i < n) {
        string a;
        while (isalpha(s[i]) && i < n) {
            a += s[i];
            i++;
        }
        string b;
        while (isdigit(s[i]) && i < n) {
            b += s[i];
            i++;
        }
        long long d = stoll(b);
        long long seglen = a.size() * d;
        if (k <= seglen) {
            return a[(k - 1) % a.size()];
        } else {
            k -= seglen;
        }
    }
    return '\0';
}

int main() {
    string s;
    long long k;
    
    cout << "Enter the encrypted string: ";
    cin >> s;
    
    cout << "Enter the value of k: ";
    cin >> k;

    char result = kThCharaterOfDecryptedString(s, k);
    
    if (result != '\0') {
        cout << "The k-th character of the decrypted string is: " << result << endl;
    } else {
        cout << "The value of k is out of range." << endl;
    }

    return 0;
}
