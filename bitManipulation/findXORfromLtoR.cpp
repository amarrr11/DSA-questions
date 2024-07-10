/*
Find XOR of numbers from L to R.

You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int tillN(int n) {
        if (n % 4 == 1) 
            n = 1;
        else if (n % 4 == 2) 
            n = n + 1;
        else if (n % 4 == 3) 
            n = 0;
        // else n = n; // This line is not necessary because n remains unchanged by default
        return n;
    }

    int findXOR(int l, int r) {
        return (tillN(l - 1) ^ tillN(r));
    }
};

int main() {
    Solution obj;
    int l, r;
    cout << "Enter l and r: ";
    cin >> l >> r;
    int result = obj.findXOR(l, r);
    cout << "XOR from " << l << " to " << r << " is: " << result << endl;
    return 0;
}
