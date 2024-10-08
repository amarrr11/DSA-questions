/*Stock span problem
Difficulty: Medium
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to 
calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given 
day, for which the price of the stock on the given day is less than or equal to its price on the current day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 
days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span 
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6. 
Hence the output will be 1 1 1 2 1 4 6.
Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span 
10 is greater than equal to 10 and there are no more elements behind it so the span is 1,
4 is greater than equal to 4 and smaller than 10 so the span is 1,
5 is greater than equal to 4,5 and smaller than 10 so the span is 2,
90 is greater than equal to all previous elements so the span is 4,
120 is greater than equal to all previous elements so the span is 5,
80 is greater than equal to 80 and smaller than 120 so the span is 1,
Hence the output will be 1 1 2 4 5 1.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n) {
        stack<int> s;
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && price[i] > price[s.top()]) {
                ans[s.top()] = s.top() - i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) { //maybe arr={10,20,30}
            ans[s.top()] = s.top() + 1;
            s.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    
    vector<int> result = sol.calculateSpan(price, n);
    
    // Output the results
    cout << "Stock Span for each day: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
