/*1497. Check If Array Pairs Are Divisible by k

Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> mp(k, 0);  // Create a vector to store the frequency of remainders
        
        // Populate the remainder frequency array
        for (int num : arr) {
            mp[(num % k + k) % k]++;  // Handle negative remainders
        }

        // If there are odd numbers of elements with remainder 0, pairing is impossible
        if (mp[0] % 2 != 0) return false;

        // Check if pairs of (i, k-i) have the same frequency
        for (int i = 1; i <= k / 2; i++) {
            int remainingHalf = k - i;
            // If remainder i and k-i don't have matching frequencies, return false
            if (mp[remainingHalf] != mp[i]) return false;
        }

        return true;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;

    if (solution.canArrange(arr, k)) {
        cout << "The array can be rearranged into pairs divisible by " << k << endl;
    } else {
        cout << "The array cannot be rearranged into pairs divisible by " << k << endl;
    }

    return 0;
}

