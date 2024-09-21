/*Search Pattern (KMP-Algorithm)
Difficulty: Medium
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the 
occurences of pattern string in the text string. Use one-based indexing while returning the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
Example 2:

Input: 
txt = "abesdu"
pat = "edu"
Output: 
-1
Explanation: 
There's not substring "edu" present in txt.*/

#include <bits/stdc++.h>
using namespace std;

class KMP {
    public:
        void lpsfind(vector<int> &lps, string str) {
            int i = 0, j = 1;
            while(j < lps.size()) {
                if(str[i] == str[j]) {
                    lps[j] = i + 1;
                    i++, j++;
                } else {
                    if(i == 0) {
                        lps[j] = 0;
                        j++;
                    } else {
                        i = lps[i - 1];
                    }
                }
            }
        }

        vector<int> search(string pat, string txt) {
            vector<int> lps(pat.size(), 0);
            lpsfind(lps, pat);
            int i = 0, j = 0;
            vector<int> ans;
            while(i < txt.size()) {
                if(pat[j] == txt[i]) {
                    i++, j++;
                } else {
                    if(j == 0) {
                        i++;
                    } else {
                        j = lps[j - 1];
                    }
                }
                if(j == pat.size()) {
                    ans.push_back(i - j + 1);
                }
            }
            return ans;
        }
};

int main() {
    string txt = "ababcabcabababd";
    string pat = "ababd";
    KMP kmp;
    vector<int> result = kmp.search(pat, txt);

    for(int pos : result) {
        cout << "Pattern found at position: " << pos << endl;
    }

    return 0;
}
