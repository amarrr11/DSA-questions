/*66. Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain 
any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int n = d.size();
        if(d[n-1] >= 0 && d[n-1] < 9) {
            d[n-1] = d[n-1] + 1;
            return d;
        }
        int carry = 0;
        for(int i = n-1; i >= 0; i--) {
            if(d[i] + 1 > 9) {
                d[i] = 0;
                carry = 1;
            } else if(carry && d[i] + 1 <= 9) {
                d[i] += 1;
                carry = 0;
                break;
            }
        }
        if(carry) {
            int a = 0;
            vector<int> v(n+1);
            v[0] = 1;
            for(int i = 1; i < n; i++) {
                v[i] = d[a++];
            }
            return v;
        }
        return d;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> digits = {9, 9, 9}; // 999 + 1 = 1000
    
    vector<int> result = sol.plusOne(digits);
    
    // Output the result
    for (int num : result) {
        cout << num;
    }
    cout << endl;

    return 0;
}
