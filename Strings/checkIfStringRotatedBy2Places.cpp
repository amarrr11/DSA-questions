// Check if string is rotated by two places
// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

// Example 1:

// Input:
// a = amazon
// b = azonam
// Output: 
// 1
// Explanation: 
// amazon can be rotated anti-clockwise by two places, which will make it as azonam.

#include <iostream>
#include <string>
using namespace std;

class RotationChecker {
public:
    bool right(string str, string str2) {
        int n = str.size();
        char c1 = str[n - 1];
        char c2 = str[n - 2];
        int i = n - 3;
        while (i >= 0) {
            str[i + 2] = str[i];
            i--;
        }
        str[0] = c2;
        str[1] = c1;
        return (str == str2);
    }

    bool left(string str, string str2) {
        int n = str.size();
        char c1 = str[0];
        char c2 = str[1];
        int i = 2;
        while (i < n) {
            str[i - 2] = str[i];
            i++;
        }
        str[n - 1] = c2;
        str[n - 2] = c1;
        return (str == str2);
    }

    bool isRotated(string str1, string str2) {
        if (right(str1, str2)) {
            return true;
        }
        if (left(str1, str2)) {
            return true;
        }
        return false;
    }
};

int main() {
    string str1, str2;

    // User input
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    RotationChecker rc;

    // Function call and output
    if (rc.isRotated(str1, str2)) {
        cout << "Second string is a rotated version of the first string." << endl;
    } else {
        cout << "Second string is not a rotated version of the first string." << endl;
    }

    return 0;
}
