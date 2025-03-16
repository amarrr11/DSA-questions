/*2594. Minimum Time to Repair Cars

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

 

Example 1:

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
Example 2:

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    typedef long long ll;
    bool ispossible(vector<int> &ranks, int cars, ll mid) {
        ll carsFixed = 0;
        for (int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid / ranks[i]);
        }
        return carsFixed >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll low = 1;
        int maxi = *max_element(ranks.begin(), ranks.end());
        ll high = 1LL * maxi * cars * cars;
        ll ans = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (ispossible(ranks, cars, mid)) {
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
    
    vector<int> ranks1 = {4, 2, 3};
    int cars1 = 6;
    cout << "Minimum time to repair " << cars1 << " cars: " << sol.repairCars(ranks1, cars1) << endl;
    
    vector<int> ranks2 = {5, 1, 8};
    int cars2 = 10;
    cout << "Minimum time to repair " << cars2 << " cars: " << sol.repairCars(ranks2, cars2) << endl;
    
    return 0;
} 