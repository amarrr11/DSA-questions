#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1 || n == 2) return true;
        if (n <= 0) return false;  // Ensure n is positive
        if (n % 2 != 0) return false;  // Check if n is even

        return isPowerOfTwo(n / 2);  // Recursive call
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Enter a number: ";
    cin >> n;  // Take a single input from the user

    // Check and output whether the input number is a power of two
    cout << "Is " << n << " a power of two? " 
         << (solution.isPowerOfTwo(n) ? "Yes" : "No") << endl;

    return 0;
}
