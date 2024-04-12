// Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside
//  the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include <iostream>
#include <limits>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x) {
            long rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return int(rev);
    }
};

int main() {
    Solution solution;
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    int reversed = solution.reverse(x);
    cout << "Reversed integer: " << reversed << endl;

    return 0;
}
