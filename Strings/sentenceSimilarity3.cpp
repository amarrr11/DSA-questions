/*1813. Sentence Similarity III

You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of 
words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and 
lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one 
of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing 
words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is
 not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(string s1, string s2) {
        // Ensure s1 is the longer string
        if (s2.size() > s1.size()) {
            swap(s1, s2);
        }

        // Convert both strings to vectors of words
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        vector<string> v1, v2;

        while (ss1 >> word) {
            v1.push_back(word);
        }
        while (ss2 >> word) {
            v2.push_back(word);
        }

        int i = 0, j = v1.size() - 1;
        int l = 0, k = v2.size() - 1;

        // Forward comparison
        while (i < v1.size() && l < v2.size() && v1[i] == v2[l]) {
            i++;
            l++;
        }

        // Backward comparison
        while (k >= l && j >= i && v1[j] == v2[k]) {
            j--;
            k--;
        }

        // If all of v2 can be matched, return true
        if (l > k) return true;
        return false;
    }
};

int main() {
    Solution sol;
    
    string s1 = "This is a sample string example";
    string s2 = "sample string";
    
    bool result = sol.canTransform(s1, s2);
    
    if (result) {
        cout << "The string \"" << s2 << "\" can be transformed into \"" << s1 << "\"" << endl;
    } else {
        cout << "The string \"" << s2 << "\" cannot be transformed into \"" << s1 << "\"" << endl;
    }

    return 0;
}
/*  stringstream ss1(s1);
    stringstream ss2(s2);
        string word;
        deque<string> d1,d2;
        while(ss1>>word){
            d1.push_back(word);
        }
        while(ss2>>word){
            d2.push_back(word);
        }

        while(!d1.empty() and !d2.empty() and d1.front()==d2.front()){
            d1.pop_front();
            d2.pop_front();
        }
        while(!d1.empty() and !d2.empty() and d1.back()==d2.back()){
            d1.pop_back();
            d2.pop_back();
        }

        return d2.empty();
        */