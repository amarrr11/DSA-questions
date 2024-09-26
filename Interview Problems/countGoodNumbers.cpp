/*1922. Count Good Numbers

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 
7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions 
are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo
109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define mod 1000000007

    long long modPow(long long b, long long p) {
        if(p == 0) {
            return 1;
        }
        long long ans = modPow(b, p / 2);
        ans *= ans;
        ans %= mod;

        if(p % 2) ans *= b;
        return ans % mod;
    }

    int countGoodNumbers(long long n) {
        long long even, odd;
        odd = n / 2;
        even = n / 2 + n % 2;
        return (modPow(5, even) * modPow(4, odd)) % mod;
    }
};

int main() {
    Solution sol;
    long long n;
    cin >> n;
    cout << sol.countGoodNumbers(n) << endl;
    return 0;
}
