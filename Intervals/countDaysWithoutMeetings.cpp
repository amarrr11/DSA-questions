/*3169. Count Days Without Meetings

You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.

 */

 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public: 
    // 0 1 2 3 4 5 6 7 8 9 10
        int countDays(int days, vector<vector<int>>& meetings) {
            // vector<int> v(days+1,0);
            // for(auto it:meetings){
            //     int low=it[0];
            //     int high=it[1];
            //     for(int i=low;i<=it[1];i++){
            //         v[i]=1;
            //     }
            // }
            // for(int i=1;i<=days;i++){
            //     if(v[i]==0) cnt++;
            // }
            // return  cnt;
            int cnt=0;
    
            sort(meetings.begin(),meetings.end());
            
            int lastEnd=0;
    
            for(int i=0;i<meetings.size();i++){
                if(meetings[i][0]>days) break;
                if(meetings[i][0]>lastEnd){
                    cnt+=(meetings[i][0]-lastEnd-1);
                }
                lastEnd=max(lastEnd,meetings[i][1]);
            }
    
            if(lastEnd<days){
                cnt+=(days-lastEnd);
            }
            return cnt;
        }
    };


int main() {
    Solution sol;
    
    int days = 10; // Total number of days
    vector<vector<int>> meetings = {{2, 3}, {5, 6}, {8, 9}}; // Example meeting intervals

    int result = sol.countDays(days, meetings);

    cout << "Number of free days: " << result << endl;

    return 0;
}
