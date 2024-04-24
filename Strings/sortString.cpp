// Given a string consisting of lowercase letters, arrange all its letters in ascending order. 

// Example 1:
// Input:
// S = "edcab"
// Output: "abcde"
// Explanation: characters are in ascending
// order in "abcde".

#include <iostream>
#include <vector>
using namespace std;

string sort(string s) {
    vector<int> lower(26, 0);
    string ans;
    for(int i = 0; i < s.size(); i++) {
        lower[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        while(lower[i]) {
            ans += ch;
            lower[i]--;
        }
    }
    return ans;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string sortedString = sort(input);

    cout << "Sorted string: " << sortedString << endl;

    return 0;
}
