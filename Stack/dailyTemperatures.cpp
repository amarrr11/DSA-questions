/*739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the
 number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is
  possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int> ans;
        stack<int> s;
        int n = v.size();
        s.push(n - 1);
        ans.push_back(0);
        
        for (int i = n - 2; i >= 0; i--) {
            while (!s.empty() && v[s.top()] <= v[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(s.top() - i);
            }
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73}; // Example input
    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Output: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    return 0;
}
