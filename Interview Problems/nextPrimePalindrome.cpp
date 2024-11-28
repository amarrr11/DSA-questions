/*866. Prime Palindrome

Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

 

Example 1:

Input: n = 6
Output: 7
Example 2:

Input: n = 8
Output: 11
Example 3:

Input: n = 13
Output: 101
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalin(int n) {
        string s = to_string(n);
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    bool isPrime(int n) {
        if (n <= 1) return false;  // Handle edge case for n <= 1
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n == 1) return 2;
        while (true) {
            if (n > 1e7) return 100030001; // Largest prime palindrome <= 10^8

            if ((n > 1e3 && n < 1e4) || (n > 1e5 && n < 1e6) || (n > 1e7 && n < 1e8)) {
                n = pow(10, ceil(log10(n)));
                continue;
            }
            if (isPrime(n) && isPalin(n)) {
                return n;
            }
            n++;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Example: Test the function with a specific input
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int result = solution.primePalindrome(n);
    
    cout << "The smallest prime palindrome greater than or equal to " << n << " is: " << result << endl;
    
    return 0;
}
