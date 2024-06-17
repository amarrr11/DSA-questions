/*
1647. Minimum Deletions to Make Character Frequencies Unique

A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.
The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        int result = 0;
        unordered_set<int> st;
        for (int i = 0; i < freq.size(); i++) {
            while (freq[i] > 0 && st.find(freq[i]) != st.end()) { //if already present in set then minus 1 and check again if that exists;
                freq[i]--;
                result++;
            }
            st.insert(freq[i]);
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input;
    
    // Taking user input
    cout << "Enter a string: ";
    cin >> input;
    
    // Calling the minDeletions function and printing the result
    int result = solution.minDeletions(input);
    cout << "Minimum deletions to make character frequencies unique: " << result << endl;
    
    return 0;
}
