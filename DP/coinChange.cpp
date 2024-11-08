/*322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a 
total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any 
combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public: 
    vector<int> dp; 

    int solve(vector<int> &coins, int amount) {
        if (amount == 0) return 0; // Base case: no amount left, zero coins needed
        if (amount < 0) return INT_MAX; // Invalid amount, return max to indicate failure
        if (dp[amount] != -1) return dp[amount]; // Return cached result if available

        int cnt = INT_MAX;
        for (int coin : coins) {
            int res = solve(coins, amount - coin);
            if (res != INT_MAX) { // Only consider valid results
                cnt = min(cnt, res + 1);
            }
        }

        dp[amount] = cnt; // Cache the result for current amount
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount + 1, -1); // Resize dp to only amount + 1 elements
        int res = solve(coins, amount);
        return res == INT_MAX ? -1 : res; // If result is max, return -1 (no solution)
    }
};

int main() {
    // Create a Solution object
    Solution solution;

    // Input for coins array
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input for the amount
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    // Call coinChange method and print the result
    int result = solution.coinChange(coins, amount);
    if (result == -1) {
        cout << "It's not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum coins needed: " << result << endl;
    }

    return 0;
}
