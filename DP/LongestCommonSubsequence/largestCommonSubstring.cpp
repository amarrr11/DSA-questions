/*1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common 
subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted
 without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.*/



#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1,string &s2,int n,int m){
        if(n==0 or m==0){
            return 0;
        }
        if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
        if(s1[n-1]==s2[m-1]){
            return dp[n-1][m-1]=1 + solve(s1,s2,n-1,m-1) ;
        }else{
            return dp[n-1][m-1]=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
        }
    }

    int longestCommonSubsequence(string s1, string s2) {
        
        dp.resize(s1.size()+2,vector<int> (s2.size()+2,-1));
        return solve(s1,s2,s1.size(),s2.size());
        
    }
};

int main() {
    // Input strings
    string s1 = "abcde";
    string s2 = "ace";

    // Create a Solution object
    Solution solution;

    // Call the function and store the result
    int lcsLength = solution.longestCommonSubsequence(s1, s2);

    // Print the result
    cout << "The length of the longest common subsequence is: " << lcsLength << endl;

    return 0;
}
