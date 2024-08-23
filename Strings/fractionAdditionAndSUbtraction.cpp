/*592. Fraction Addition and Subtraction

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in 
string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction 
that has a denominator 1. So in this case, 2 should be converted to 2/1.


Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 */

#include <iostream>
#include <string>
#include <algorithm> // for __gcd
using namespace std;

class Solution {
public:
    string fractionAddition(string s) {
        int n = s.size();
        int num = 0;
        int den = 1;
        int i = 0;
        while (i < n) {
            int currNum = 0, currDen = 0;
            bool isNeg = false;
            if (s[i] == '-') {
                isNeg = true;
                i++;
            } else if (s[i] == '+') {
                i++;
            }
            while (i < n && isdigit(s[i])) {
                currNum = currNum * 10 + (s[i] - '0');
                i++;
            }
            if (isNeg) {
                currNum *= -1;
                isNeg = false;
            }
            if (s[i] == '/') {
                i++;
            }
            while (i < n && isdigit(s[i])) {
                currDen = currDen * 10 + (s[i] - '0');
                i++;
            }
            if (num == 0 && den == 1) {
                num = currNum;
                den = currDen;
            } else {
                num = (num * currDen) + (den * currNum);
                den = (currDen * den);
            }
        }
        int GCD = abs(__gcd(num, den));
        num /= GCD;
        den /= GCD;

        return to_string(num) + "/" + to_string(den);
    }
};

int main() {
    Solution solution;
    string input = "-1/2+1/2+1/3"; // Example input string
    string result = solution.fractionAddition(input);
    cout << "The result of fraction addition is: " << result << endl;
    return 0;
}
    