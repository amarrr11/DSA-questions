/*Egg Dropping Puzzle
Difficulty: MediumAccuracy: 39.64%Submissions: 150K+Points: 4
You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped
 from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the egg breaks on a certain floor, it will break on any floor above.
Return the minimum number of moves you need to determine the value of f with certainty.

Examples:

Input: n = 1, k = 2
Output: 2
Explanation: Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2.If it breaks,
 we know that f = 1.  If it does not break, then we know f = 2. Hence, we need at minimum 2 moves to determine with certainty 
 what the value of f is.
Input: n = 10, k = 5
Output: 3
Explanation: Drop the egg from floor 2. If it breaks, test floor 1 with a remaining egg.If it doesn’t break, drop from floor 4.
 If it breaks, test floor 3. If it still doesn’t break, we know the critical floor is 5.Hence, with a minimum of 3 moves, we
  can find the critical floor.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int e, int f) {
    if (f == 0 || f == 1) {
        return f;
    }
    if (e == 1) {
        return f; // If only one egg, worst case is dropping from each floor
    }
    if (dp[e][f] != -1) return dp[e][f];

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++) {
        int low = (dp[e-1][k-1] != -1) ? dp[e-1][k-1] : solve(e-1, k-1);
        int high = (dp[e][f-k] != -1) ? dp[e][f-k] : solve(e, f-k);
        int temp = 1 + max(low, high);
        mini = min(mini, temp);
    }
    return dp[e][f] = mini;
}

int eggDrop(int n, int k) {
    dp.assign(n + 1, vector<int>(k + 1, -1)); // Correctly resizing dp
    return solve(n, k);
}

int main() {
    int eggs, floors;
    cout << "Enter the number of eggs: ";
    cin >> eggs;
    cout << "Enter the number of floors: ";
    cin >> floors;

    int result = eggDrop(eggs, floors);
    cout << "Minimum attempts needed to find the critical floor: " << result << endl;

    return 0;
}
