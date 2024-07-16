/*187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than 
once in a DNA molecule. You may return the answer in any order.

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() <= 10) return ans;
        unordered_map<string, int> mp;

        for(int i = 0; i <= s.size() - 10; i++) {
            string temp = s.substr(i, 10);
            mp[temp]++;
        }
        for(auto i : mp) {
            if(i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string input1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string input2 = "AAAAAAAAAAAAA";

    vector<string> result1 = solution.findRepeatedDnaSequences(input1);
    vector<string> result2 = solution.findRepeatedDnaSequences(input2);

    cout << "Repeated DNA sequences in \"" << input1 << "\":" << endl;
    for(const string& seq : result1) {
        cout << seq << endl;
    }

    cout << "Repeated DNA sequences in \"" << input2 << "\":" << endl;
    for(const string& seq : result2) {
        cout << seq << endl;
    }

    return 0;
}
