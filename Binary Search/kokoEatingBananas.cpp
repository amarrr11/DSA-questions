/*
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will 
come back in h hours.Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas 
and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any
more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long total(int mid, vector<int>& piles) {
        long long n = piles.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (piles[i] + mid - 1) / mid;  //ceil (piles[i]/mid)
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        int low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = total(mid, piles);
            if (sum <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // User input for number of piles
    int numPiles;
    cout << "Enter the number of piles: ";
    cin >> numPiles;

    // User input for the piles
    vector<int> piles(numPiles);
    cout << "Enter the piles: ";
    for (int i = 0; i < numPiles; i++) {
        cin >> piles[i];
    }

    // User input for hours h
    int h;
    cout << "Enter the number of hours: ";
    cin >> h;

    // Calculate and display the minimum eating speed
    int result = sol.minEatingSpeed(piles, h);
    cout << "The minimum eating speed is: " << result << endl;

    return 0;
}
