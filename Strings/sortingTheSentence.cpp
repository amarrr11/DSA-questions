// 1859. Sorting the Sentence

// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word 
// consists of lowercase and uppercase English letters.
// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

// Example 1:

// Input: s = "is2 sentence4 This1 a3"
// Output: "This is a sentence"
// Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
// Example 2:

// Input: s = "Myself2 Me1 I4 and3"
// Output: "Me Myself and I"
// Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.
 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int count=0; // to iterate at the end till count to store in and vector
        string temp;
        int index=0;
        while(index<s.size()){
            if(s[index]==' '){
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear(); //to take other element
                count++;
            }
            else{
                temp+=s[index];
            }
            index++;
        }
         // repeat the step cause temp has still a value as at the end it hasn't encountered " " so it has not 
         //been stored in ans vector.
        int pos=temp[temp.size()-1]-'0';
        temp.pop_back();
        ans[pos]=temp;
        temp.clear();
        count++;

        for(int i=1;i<=count;i++){
            temp+=ans[i];
            temp+=' ';
        }
        temp.pop_back();
        return temp;
    }
};

// As in the input , every word is followed by 1 number which states its position right? And that could be 1-9 given.
// So we make an answer vector where we will be storing each string.So first we iterate and then as we encounter a digit,
// we stops and store that digit as position.Then to store the word we pop_back the temo string which consist of the string
// till digit.Then we write the string in that position in answer vector,then we increase the count by 1.We are actually
// keeping a count integer so as to see how many words we are having at the end of the iteration and we will only look
// till that vector.Then cause the while loop condition is till we get space ' ', so at the end of the sentence which
// encounter a null value not a space,still the temp varibale will be having a value.So we do the same process after
// the loop once.

int main() {
    Solution obj;
    string input;
    
    cout << "Enter the sentence: ";
    getline(cin, input);
    
    string sortedSentence = obj.sortSentence(input);
    
    cout << "Sorted sentence: " << sortedSentence << endl;
    
    return 0;
}
