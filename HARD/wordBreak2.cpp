/*140. Word Break II

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid 
dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        unordered_set<string> st;
        vector<string> ans;
    
        void solve(int idx,string &curr,string &s){
    
            if(idx>=s.size()){
                ans.push_back(curr);
                return;
            }
    
            for(int j=idx;j<s.size();j++){
                string temp=s.substr(idx,j-idx+1);
    
                if(st.count(temp)){
                    string t=curr;
                    if(!curr.empty()){
                        curr+=" ";
                    }
                    curr+=temp;
                    solve(j+1,curr,s);
                    curr=t;
                }
            }
        }
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            for(auto &w:wordDict){
                st.insert(w);
            }
            
            string curr="";
            solve(0,curr,s);
            return ans;
        }
    };

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    
    vector<string> result = sol.wordBreak(s, wordDict);
    
    cout << "Possible sentences:" << endl;
    for (const string &sentence : result) {
        cout << sentence << endl;
    }
    
    return 0;
}
