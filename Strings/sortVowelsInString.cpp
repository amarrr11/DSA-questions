// 2785. Sort Vowels in a String

// Given a 0-indexed string s, permute s to get a new string t such that:

// All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant,
//  then t[i] = s[i].
// The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length
// such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
// Return the resulting string.
// Example 1:

// Input: s = "lEetcOde"
// Output: "lEOtcede"
// Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII
//  values, and the consonants remain in the same places.
// Example 2:

// Input: s = "lYmpH"
// Output: "lYmpH"
// Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
     
    string sortVowels(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                lower[s[i]-'a']++;
                s[i]='#';
            }
            else if(s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
                upper[s[i]-'A']++;
                s[i]='#';
            }
        }
        for(int i=0;i<26;i++){
            char ch=i+'A';
            while(upper[i]){
                temp+=ch;
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++){
            char ch=i+'a';
            while(lower[i]){
                temp+=ch;
                lower[i]--;
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                s[i]=temp[j++];
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    string sortedString = solution.sortVowels(input);
    cout << "Sorted string with vowels moved to the end: " << sortedString << endl;
    return 0;
}
