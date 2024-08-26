/*3265. Count Almost Equal Pairs I

You are given an array nums consisting of positive integers.

We call two integers x and y in this problem almost equal if both integers can become equal after performing the following 
operation at most once:

Choose either x or y and swap any two digits within the chosen number.
Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.

Note that it is allowed for an integer to have leading zeros after performing an operation.

 

Example 1:

Input: nums = [3,12,30,17,21]

Output: 2

Explanation:

The almost equal pairs of elements are:

3 and 30. By swapping 3 and 0 in 30, you get 3.
12 and 21. By swapping 1 and 2 in 12, you get 21.
Example 2:

Input: nums = [1,1,1,1,1]

Output: 10

Explanation:

Every two elements in the array are almost equal.

Example 3:

Input: nums = [123,231]

Output: 0

Explanation:

We cannot swap any two digits of 123 or 231 to reach the other.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isEqualPair(int n, int m) {

        string s1 = to_string(n);
        string s2 = to_string(m);
        int maxi = s1.size() > s2.size() ? s1.size() : s2.size();

        while (s1.size() != maxi) {
            s1 = "0" + s1;
        }
        while (s2.size() != maxi) {
            s2 = "0" + s2;
        }

        int diff = 0;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        return diff <= 2 && mp1 == mp2;
    }

    int countPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isEqualPair(nums[i], nums[j])) cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {123, 321, 132, 213, 231, 312};  // Example input
    int result = sol.countPairs(nums);
    cout << "Number of equal pairs: " << result << endl;

    return 0;
}
