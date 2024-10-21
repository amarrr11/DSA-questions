/*326. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true; // 3^0=1
        if (n == 0) return false;
        if (n % 3 != 0) return false;

        return isPowerOfThree(n / 3);
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter a number: ";
    cin >> n;  // Take a single input from the user

    // Check and output whether the input number is a power of three
    cout << "Is " << n << " a power of three? " 
         << (solution.isPowerOfThree(n) ? "Yes" : "No") << endl;

    return 0;
}
