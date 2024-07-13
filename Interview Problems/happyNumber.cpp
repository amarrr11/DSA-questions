/*202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false*/

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        long long sum = 0;
        set<int> s;
        while (n) {
            int digit = n % 10;
            digit *= digit;
            sum += digit;
            n /= 10;
            if (!n) {
                if (s.find(sum) != s.end()) return false;
                if (sum == 1) return true;
                else {
                    s.insert(sum);
                    n = sum;
                    sum = 0;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int num1 = 19;
    cout << "Is " << num1 << " a happy number? " << (solution.isHappy(num1) ? "Yes" : "No") << endl;
    
    // Example 2
    int num2 = 2;
    cout << "Is " << num2 << " a happy number? " << (solution.isHappy(num2) ? "Yes" : "No") << endl;
    
    // Example 3
    int num3 = 7;
    cout << "Is " << num3 << " a happy number? " << (solution.isHappy(num3) ? "Yes" : "No") << endl;
    
    // Example 4
    int num4 = 20;
    cout << "Is " << num4 << " a happy number? " << (solution.isHappy(num4) ? "Yes" : "No") << endl;
    
    return 0;
}
