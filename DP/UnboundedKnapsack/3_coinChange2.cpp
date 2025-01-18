/*518. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a 
total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination
 of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int amt, vector<int> &coins, int idx) {
        if (amt == 0) {
            return 1;
        }
        if (amt < 0 || idx >= coins.size()) {
            return 0;
        }
        if (dp[idx][amt] != -1) return dp[idx][amt];
        // for (int i = idx; i < coins.size(); i++) {
        //     int res = solve(amt - coins[i], coins, idx + 1);
        //     if (res != INT_MAX) {
        //         ans++;
        //     }
        // }

        return dp[idx][amt] = solve(amt - coins[idx], coins, idx) + solve(amt, coins, idx + 1);
    }

    //2nd wayyyyyyyyyyyyyyy
    int solve(vector<int> &coins,int sum,int i,vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i>=coins.size() or sum<0) return 0;
        
        
        if(dp[sum][i]!=-1) return dp[sum][i];
        int notTake=0+solve(coins,sum,i+1,dp);
        
        int take=0;
        if(coins[i]<=sum){
            take=max(solve(coins,sum-coins[i],i,dp),solve(coins,sum-coins[i],i+1,dp));
        }
        return dp[sum][i]=take+notTake;
        
    }

    int change(int amount, vector<int>& coins) {
        dp.resize(305, vector<int>(5002, -1));
        return solve(amount, coins, 0);   
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};  // Example coin denominations
    int amount = 5;  // Example amount to make change for

    int result = solution.change(amount, coins);
    cout << "Number of ways to make change: " << result << endl;

    return 0;
}
