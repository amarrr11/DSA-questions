/*1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are 
multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string 
s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    string ans;
    string solve(string s1, string s2,int n,int m){
        if(n==0 or m==0){
            return "";
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=n,j=m;
        while(i>0 and j>0){
            // if(dp[i][j]==dp[i-1][j-1]+1){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans+=s1[i-1];
                    i--;
                }else{
                    ans+=s2[j-1];
                    j--;
                }
            }

           
        }

        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(str1,str2,n,m);
        
        
    }
};
int main() {
    Solution sol;

    // Test Case 1
    string str1 = "abac";
    string str2 = "cab";
    string result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence of \"" << str1 << "\" and \"" << str2 << "\": " << result << endl;

    // Test Case 2
    str1 = "geek";
    str2 = "eke";
    result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence of \"" << str1 << "\" and \"" << str2 << "\": " << result << endl;

    // Test Case 3
    str1 = "abc";
    str2 = "def";
    result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence of \"" << str1 << "\" and \"" << str2 << "\": " << result << endl;

    return 0;
}