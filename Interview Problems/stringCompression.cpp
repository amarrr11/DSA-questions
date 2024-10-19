/*443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array     should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& arr) {
        int n = arr.size();
        int i = 1;
        int cnt = 0;
        vector<char> nums;
        while (i < n) {
            if (arr[i] == arr[i - 1]) {
                cnt++;
            } else {
                nums.push_back(arr[i - 1]);
                if (cnt + 1 == 1) {
                    cnt = 0;
                    i++;
                    continue;
                } else {
                    string temp = to_string(cnt + 1);
                    for (char c : temp) {
                        nums.push_back(c);
                    }
                }
                cnt = 0;
            }
            i++;
        }
        nums.push_back(arr[i - 1]);
        if (cnt != 0) {
            string temp = to_string(cnt + 1);
            for (char c : temp) {
                nums.push_back(c);
            }
        }
        arr = nums;
        return arr.size();
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<char> arr1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int compressedLength1 = solution.compress(arr1);
    cout << "Compressed Length: " << compressedLength1 << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength1; i++) {
        cout << arr1[i];
    }
    cout << endl;

    // Test case 2
    vector<char> arr2 = {'a'};
    int compressedLength2 = solution.compress(arr2);
    cout << "Compressed Length: " << compressedLength2 << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength2; i++) {
        cout << arr2[i];
    }
    cout << endl;

    // Test case 3
    vector<char> arr3 = {'a', 'b', 'c'};
    int compressedLength3 = solution.compress(arr3);
    cout << "Compressed Length: " << compressedLength3 << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength3; i++) {
        cout << arr3[i];
    }
    cout << endl;

    // Test case 4
    vector<char> arr4 = {'a', 'a', 'a', 'a', 'b', 'b', 'c'};
    int compressedLength4 = solution.compress(arr4);
    cout << "Compressed Length: " << compressedLength4 << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength4; i++) {
        cout << arr4[i];
    }
    cout << endl;

    return 0;
}
