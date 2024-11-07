/*
2275. Largest Combination With Bitwise AND Greater Than Zero

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of 
candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

 

Example 1:

Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
Example 2:

Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& v) {
        int n = v.size();
        int maxi = INT_MIN;
        for (int i = 0; i < 31; i++) {
            int cnt = 0;
            for (int j : v) {
                if (j & (1 << i)) cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> v = {16, 17, 71, 62, 12, 24, 14};
    int result = sol.largestCombination(v);
    cout << "The largest combination count of elements with common bits is: " << result << endl;
    return 0;
}
