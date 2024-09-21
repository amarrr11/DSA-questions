/*214. Shortest Palindrome

You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.


Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findLps(vector<int> &lps, string s) {
        int i = 0, j = 1;
        while (j < s.size()) {
            if (s[i] == s[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0) {
                    j++;
                } else {
                    i = lps[i - 1];
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return "";

        string ori = s;
        reverse(s.begin(), s.end());
        string rev = s;
        if (ori == rev) return s;

        string str = ori + '#' + rev;
        vector<int> lps(str.size(), 0);
        findLps(lps, str);

          //kitna match hua h last element me hi rhega

        int n = lps[lps.size() - 1];

        string temp = ori.substr(n);
        reverse(temp.begin(), temp.end());

        return temp + ori;


    } /********************************************************************************** */



    // int n=s.size();
        // string rev=s;
        // reverse(rev.begin(),rev.end());

        // for(int i=0;i<n;i++){
        //     if(!memcmp(s.c_str(),rev.c_str()+i,s.size()-i)){
        //         return rev.substr(0,i)+s;
        //     }
        // }
        
        // return rev+s;

        /********************************************************************************** */

        
        // reverse(s.begin(),s.end());
        // string s1=s;
        // reverse(s.begin(),s.end());
        // int i=1;

        // while(i<s1.size())
        // {
        //     string temp=s1.substr(0,i);
        //     s=temp+s;
        //     if(isPalin(s)) return s;
        //     else{
        //         s=s.substr(i,s.size());
        //     }
        //     i++;
        // }
    
        // return s;
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "aacecaaa";
    cout << "Shortest Palindrome for " << s1 << " is: " << solution.shortestPalindrome(s1) << endl;

    // Test case 2
    string s2 = "abcd";
    cout << "Shortest Palindrome for " << s2 << " is: " << solution.shortestPalindrome(s2) << endl;

    // Test case 3
    string s3 = "racecar";
    cout << "Shortest Palindrome for " << s3 << " is: " << solution.shortestPalindrome(s3) << endl;

    return 0;
}
