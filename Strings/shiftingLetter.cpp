/*848. Shifting Letters

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
Example 2:

Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        // for(int i=0;i<shifts.size();i++){
        //     long long shift=shifts[i]%26;
        //     for(int j=0;j<=i;j++){
        //         s[j]= ((s[j]-'a')+shift)%26 + 'a';
        //     }
            
        // }
        // return s;

        reverse(shifts.begin(),shifts.end());
        for(int i=1;i<shifts.size();i++){
            shifts[i]=(shifts[i] * 1LL+shifts[i-1])%26;
            //3 5 6
        }

        reverse(s.begin(),s.end());

        int i=0;
        for(char ch:s){
            s[i]= ((ch-'a')+shifts[i])%26 + 'a';
            i++;
        }

        reverse(s.begin(),s.end());
        return s;
        

    }
};
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "mkgfzkkuxownxvfvxasy";
    vector<int> shifts1 = {505870226, 437526072, 266740649, 224336793, 532917782,
                           311122363, 567754492, 595798950, 81520022, 684110326,
                           137742843, 275267355, 856903962, 148291585, 919054234,
                           467541837, 622939912, 116899933, 983296461, 536563513};
    cout << "Test Case 1:" << endl;
    cout << "Input: " << s1 << endl;
    cout << "Shifts: [ ";
    for (int x : shifts1) cout << x << " ";
    cout << "]" << endl;
    cout << "Output: " << sol.shiftingLetters(s1, shifts1) << endl;
    cout << "---------------------------------" << endl;

    // Test Case 2
    string s2 = "abc";
    vector<int> shifts2 = {3, 5, 9};
    cout << "Test Case 2:" << endl;
    cout << "Input: " << s2 << endl;
    cout << "Shifts: [ ";
    for (int x : shifts2) cout << x << " ";
    cout << "]" << endl;
    cout << "Output: " << sol.shiftingLetters(s2, shifts2) << endl;
    cout << "---------------------------------" << endl;

    // Test Case 3
    string s3 = "zaza";
    vector<int> shifts3 = {1, 2, 3, 4};
    cout << "Test Case 3:" << endl;
    cout << "Input: " << s3 << endl;
    cout << "Shifts: [ ";
    for (int x : shifts3) cout << x << " ";
    cout << "]" << endl;
    cout << "Output: " << sol.shiftingLetters(s3, shifts3) << endl;
    cout << "---------------------------------" << endl;

    return 0;
}