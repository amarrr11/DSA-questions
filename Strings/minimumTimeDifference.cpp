/*539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points
in the list. 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> minutes;
        int ans = INT_MAX;
        
        for(int i = 0; i < tp.size(); i++) {
            int min = stoi(tp[i].substr(0, 2));
            min *= 60;
            if(min == 0 && stoi(tp[i].substr(3, 2)) == 0) {
                min = 24 * 60;
            }
            min += (stoi(tp[i].substr(3, 2)));    
            minutes.push_back(min);    
        }
        
        sort(minutes.begin(), minutes.end());

        for(int i = 0; i < minutes.size() - 1; i++) {
            ans = min(ans, minutes[i + 1] - minutes[i]);
        }
        
        ans = min(ans, 1440 - minutes.back() + minutes[0]);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> timePoints = {"23:59", "00:00", "12:30", "05:45"};
    
    int result = sol.findMinDifference(timePoints);
    cout << "The minimum time difference is: " << result << " minutes" << endl;
    
    return 0;
}
