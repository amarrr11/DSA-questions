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
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];
        int cnt = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int a = solve(coins, amount - coins[i]);
            if (a != INT_MAX) {
                cnt = min(cnt, a + 1);
            }
        }
        return dp[amount] = cnt;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount + 1, -1);
        int res = solve(coins, amount);
        if (res == INT_MAX) return -1;
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};  // Example coin denominations
    int amount = 11;  // Example amount

    int result = solution.coinChange(coins, amount);
    if (result != -1) {
        cout << "Minimum coins required: " << result << endl;
    } else {
        cout << "Amount cannot be made with given coins" << endl;
    }

    return 0;
}
