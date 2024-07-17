/*Problem statement
You are given a positive integer ‘n’. Your task is to find the largest prime factor of this given positive integer.

Note :
If there is no prime factor of a given integer, then print -1.*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the largest prime factor
int largestPrimeFactor(int n) {
    int ans = -1;
    
    // Check for factors from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = i;
            // Divide n by i until it is no longer divisible
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    
    // If n is greater than 1, then it is a prime number
    if (n > 1) return n;

    return ans;
}

int main() {
    int n;
    
    // Input number from user
    cout << "Enter a number: ";
    cin >> n;
    
    // Find and output the largest prime factor
    int result = largestPrimeFactor(n);
    cout << "The largest prime factor of " << n << " is " << result << endl;

    return 0;
}
