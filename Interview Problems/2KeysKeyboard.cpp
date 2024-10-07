/*650. 2 Keys Keyboard

There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for 
each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int prime(int n) {
        int sum = 0;
        
        // Handle factor 2
        while (n % 2 == 0) {
            sum += 2;
            n /= 2;
        }
        
        // Handle odd factors
        for (int i = 3; i <= n; i += 2) {
            while (n % i == 0) {
                sum += i;
                n /= i;
            }
        }
        
        return sum;
    }
    
    int minSteps(int n) {
        int sum = prime(n);
        return sum;
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter a number: ";
    cin >> n;
    
    int result = sol.minSteps(n);
    
    cout << "The sum of prime factors for " << n << " is: " << result << endl;
    
    return 0;
}
