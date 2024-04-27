// 13. Roman to Integer

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

//Approach: If the next element is greater than the curent then the current is subracted from the sum like IX is 9;

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int number(char c) {
        if (c == 'I') {
            return 1;
        } else if (c == 'V') {
            return 5;
        } else if (c == 'X') {
            return 10;
        } else if (c == 'L') {
            return 50;
        } else if (c == 'C') {
            return 100;
        } else if (c == 'D') {
            return 500;
        } else if (c == 'M') {
            return 1000;
        }
        return -1;
    }

public:
    int romanToInt(string s) {
        int idx = 0;
        int sum = 0;
        while (idx < s.size() - 1) {
            if (number(s[idx]) < number(s[idx + 1])) {
                sum = sum - number(s[idx]);
            } else {
                sum = sum + number(s[idx]);
            }
            idx++;
        }
        sum += number(s[s.size() - 1]);
        return sum;
    }
};

int main() {
    Solution obj;
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;
    int result = obj.romanToInt(romanNumeral);
    cout << "The integer value of " << romanNumeral << " is: " << result << endl;
    return 0;
}
