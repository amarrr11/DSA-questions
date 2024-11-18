/*0 - 1 Knapsack Problem

You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to 
achieve the maximum total value in the knapsack. Each item is available in only one quantity.

In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with 
items, respectively. You are also given an integer capacity, which represents the knapsack capacity. Your task is to find
 the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than
  or equal to capacity. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

Examples :

Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3] 
Output: 50
Explanation: Choose the second item (value 40, weight 4) and the fourth item (value 50, weight 3) for a total weight of 
7, which exceeds the capacity. Instead, pick the last item (value 50, weight 3) for a total value of 50.*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[1005][1005];

int solve(int capacity, vector<int> &val, vector<int> &wt, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    
    if (dp[capacity][n] != -1) return dp[capacity][n];
    
    if (wt[n - 1] <= capacity) {
        return dp[capacity][n] = max(val[n - 1] + solve(capacity - wt[n - 1], val, wt, n - 1),
                                     solve(capacity, val, wt, n - 1));
    } else {
        return dp[capacity][n] = solve(capacity, val, wt, n - 1);
    }
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    memset(dp, -1, sizeof(dp));
    return solve(capacity, val, wt, val.size());
}

int main() {
    int capacity;
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<int> val(n), wt(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    
    int maxVal = knapSack(capacity, val, wt);
    cout << "The maximum value that can be put in the knapsack is: " << maxVal << endl;
    
    return 0;
}
