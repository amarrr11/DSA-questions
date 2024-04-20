// Print the Kth Digit
// Problem statement
// You are given three non-negative integers N, M, and K. Your task is to print the Kth digit from the right in ‘N’ raised to the power ‘M’ that is, in N ^ M.
// 1) It is guaranteed that the Kth digit from the right always exists.
// 2) It is also guaranteed that 'K' is always less than or equal to the number of digits in N ^ M.
// 3) 'N' and 'M 'can’t be a 0 simultaneously.
// Sample Input 1:
// 1
// 2 4 1
// Sample Output 1:
// 6
// Explanation for sample input 1:
// 2 ^ 4 = 16, and the 1st digit in 16 from the right is 6.
// Sample Input 2:
// 1
// 3 3 2       
// Sample Output 2:
// 2
// Explanation for sample input 2:
// 3^3 = 27, and the 2nd digit in 27 from the right is 2.

#include <bits/stdc++.h> 
using namespace std;

int findKthFromRight(int n, int m, int k) {
    long long p = pow(n, m);
    int ans = 0;
    int i = 0;
    while (p > 0) {
        int rem = p % 10;
        i += 1;
        if (i == k) {
            ans = rem;
            break;
        }
        p /= 10;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << findKthFromRight(n, m, k) << endl;
    }

    return 0;
}
