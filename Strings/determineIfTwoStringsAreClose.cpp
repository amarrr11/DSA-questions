/*
1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
    
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (char i : str1) {
            count1[i - 'a']++;
        }
        for (char i : str2) {
            count2[i - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count1[i] != 0 && count2[i] != 0) continue;
            else if (count1[i] == 0 && count2[i] == 0) continue;
            return false;
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
        // if(str1.size() != str2.size()) return false;
        // unordered_map<int,int> m1;
        // vector<int> a;
        // vector<int> b;

        // for(auto i:str1){
        //     m1[i-'0']++;    
        // }
        // for(auto i:m1){
        //     a.push_back(i.second);
        // }

        // unordered_map<int,int> m2;
        
        // for(auto i:str2){
        //     m2[i-'0']++;
        // }
        // for(auto i:m1){
        //     if(m2.find(i.first) != m2.end()){
        //         continue;
        //     } else {
        //         return false;
        //     }
        // }

        // for(auto i:m2){
        //     b.push_back(i.second);
        // }
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        // return a == b;
    }
};

int main() {
    Solution solution;

    string str1 = "abc";
    string str2 = "bca";

    bool result = solution.closeStrings(str1, str2);

    if (result) {
        cout << "The strings are close." << endl;
    } else {
        cout << "The strings are not close." << endl;
    }

    return 0;
}
