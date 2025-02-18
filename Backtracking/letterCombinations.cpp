/*17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> ans;
        unordered_map<char,string> mp;
        void solve(int idx,string &s,string &curr){
            
            if(idx>=s.size()){
                ans.push_back(curr);
                return;
            }
            
            string temp=mp[s[idx]];
    
            for(int i=0;i<temp.size();i++){
                curr+=temp[i];
                solve(idx+1,s,curr);
                curr.pop_back();
            }
    
        }    
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {};
            ans.clear();
            mp['2']="abc";
            mp['3']="def";
            mp['4']="ghi";
            mp['5']="jkl";
            mp['6']="mno";
            mp['7']="pqrs";
            mp['8']="tuv";
            mp['9']="wxyz";
    
            string temp="";
            solve(0,digits,temp);
            
            return ans;
        }
    };

int main() {
    Solution sol;
    
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "Letter Combinations: ";
    if (result.empty()) {
        cout << "[]";
    } else {
        cout << "[ ";
        for (const string &s : result) {
            cout << "\"" << s << "\" ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}
