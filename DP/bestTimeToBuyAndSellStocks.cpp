/*121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to 
sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.*/

//piche se dkh : agar mujhe 4 pe bechna hai to left me 4 se chota sbse minimum me khridunga
// same har element k liye left me jo sbse minimum hai uspe khridunga

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int ans = 0, mini = INT_MAX;
    for (int i = 1; i < n; i++) {
        mini = min(mini, arr[i - 1]);
        ans = max(ans, arr[i] - mini);
    }
    return ans;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input for stock prices
    int profit = maxProfit(prices);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
