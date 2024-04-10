//Given an integer n, return the number of prime numbers that are strictly less than n.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 0) {
            return 0;
        }
        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isprime[i]) {
                for(int j = 2 * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        int count = 0;
        for(bool i : isprime) {
            if(i) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 20; // Example input
    cout << "Number of primes less than " << n << ": " << sol.countPrimes(n) << endl;
    return 0;
}
