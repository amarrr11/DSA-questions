/*739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the 
number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is 
possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        int n = temp.size();
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() and temp[i] >= temp[s.top()]) { // s.top() gives index
                s.pop();
            }
            if (s.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }

        return ans;

        // Old code, now commented out
        // for (int i = n - 1; i >= 0; i--) {
        //     if (s.empty()) {
        //         s.push(temp[i]);
        //         ans.push_back(0);
        //     }
        //     if (temp[i] >= s.top()) {
        //         while (s.top() < temp[i]) {
        //             s.pop();
        //         }
        //         if (s.empty()) {
        //             ans.push_back(0);
        //         }
        //         s.push(temp[i]);
        //         ans[i] = s.top();
        //     } else {
        //         s.push(temp[i]);
        //         ans[i] = s.top();
        //     }
        // }
        // return ans;

        // Old code, now commented out
        // int i = 0;
        // int j = 1;
        // while (j < n) {
        //     if (temp[j] > temp[i]) {
        //         ans[i] = j - i;
        //         i++;
        //         j = i + 1;
        //     } else if (i != n - 1 and j == n - 1) {
        //         ans[i] = 0;
        //         i++;
        //         j = i + 1;
        //     } else {
        //         j++;
        //     }
        // }
        // return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Daily Temperatures Result: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
