#include <iostream>
using namespace std;

int longest(string s) {
    int cntF = 0, cntBB = 0, ins = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'F') {
            cntF++;
        } else if ((i + 1) < s.length() && s[i] == 'B' && s[i + 1] == 'B') {
            cntBB++;
            i++; // Skip next 'B'
        } else {
            ins++;
        }
    }

    ins += max(0, (cntF - cntBB)) * 2;  // Ensure non-negative value
    return ins;
}

int main() {
    string s;
    cin >> s;
    cout << longest(s);
    return 0;
}