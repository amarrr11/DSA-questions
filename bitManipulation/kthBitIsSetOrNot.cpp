//  Check whether K-th bit is set or not
// Problem statement
// Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.

// Example:
// Input: ‘N’ = 5, ‘K’ = 1

// Output: YES

// 5 in binary can be written as 101 and as we can see a first bit from the right of 5 is set so the answer is 'YES'.

#include <iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    // Check if the kth bit is set using left shift
    if (n & (1 << (k ))) {
        return true;
    }
    return false;

    //by right shift
    // if(1&(n>>(k-1))){
    //     return true;
    // }
    // return false;

}

int main() {
    int n, k;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter the position of the bit (k): ";
    cin >> k;

    bool result = isKthBitSet(n, k);

    if (result) {
        cout << "The " << k << "th bit of " << n << " is set (1)." << endl;
    } else {
        cout << "The " << k << "th bit of " << n << " is not set (0)." << endl;
    }

    return 0;
}
