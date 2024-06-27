/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase 
English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int m[26]={0};
        int l=0,r=0,ans=0,maxF=0;
        while(r<n){
            m[s[r]-'A']++;
            maxF=max(maxF,m[s[r]-'A']);
            int maxLen=r-l+1; 
            
            while((maxLen-maxF)>k){
                m[s[l]-'A']--;
                maxF=0;
                for(int i=0;i<26;i++){
                    maxF=max(maxF,m[i]);
                }
                l++;
                maxLen=r-l+1;
            }
            if(maxLen-maxF<=k){
                ans=max(ans,maxLen);
            }
            r++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "ABAB";
    int k = 2;
    cout << "Length of longest substring after replacement: " << sol.characterReplacement(s, k) << endl;
    
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Length of longest substring after replacement for s2: " << sol.characterReplacement(s2, k2) << endl;  // Output: 4
    
    return 0;
}
    
