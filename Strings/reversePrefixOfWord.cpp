// 2000. Reverse Prefix of Word
// Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the
//  index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 
// (inclusive). The resulting string will be "dcbaefd".


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {

        string ans="";
        bool flag=true;
        for(char c:word){
            
            if(c==ch && flag==true){
                ans+=c;
                reverse(ans.begin(),ans.end());
                flag=false;
            }
            else{
                ans+=c;
            }
        }
        return ans;

        // Alternative implementation without using reverse function
        // int idx=0;
        // string ans;
        // for(int i=0;i<word.size();i++){
        //     if(word[i]==ch){
        //         idx=i;
        //         break;
        //     }
        // }
        // if(idx==0){
        //     return word;
        // }
        // for(int i=idx;i>=0;i--){
        //     ans+=word[i];
        // }
        // for(int i=idx+1;i<word.size();i++){
        //     ans+=word[i];
        // }
        // return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Get input from the user
    string word;
    char ch;
    cout << "Enter the word: ";
    cin >> word;
    cout << "Enter the character: ";
    cin >> ch;

    string result = solution.reversePrefix(word, ch);
    cout << "Result: " << result << endl;

    return 0;
}
