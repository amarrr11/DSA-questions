/*3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Approach
At first (it is said that) the input could be any character,so we will make a vector of boolean type which will contain 256
characters.

Then We will take 2 pointers "first" and "second",then we will iterate the second pointer through the input and make each 
character 1.As soon as we encounter a 1 already present in the boolean vector we had assigned it means that the character 
is already addressed which means we will have to delete till the element .

For eg, abcabcbb , here we will get 1 already assigned at position 6th as c is already there so to find the max length we
will have to delete till the first c we have encountered which means we will have to remove 'abc'.

So we will start iterating the "first" pointer and make each element 0 till we get to 'c', as soon as it is c we will again
start running in our main loop andd continue with the second pointer.

Then we can get the length by subtracting first from second pointer and minus 1 cause it is 0 indexed.

Complexity
Time complexity:
O(n) cause we are iterating only on one side

Space complexity:
O(1) cause taking constant space of 256 bits*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256,0);
        int first=0;
        int second=0;
        int len=0;
        while(second < s.size()){
            while(count[s[second]]==1){ //it has been encountered before
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            len=max(len,second-first+1);
            second++;
        } 
        return len;
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int result = sol.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}
