/*42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it
 can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = h[0];
        rightMax[n-1] = h[n-1];
        
        // Calculate left max heights
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], h[i]);
        }
        
        // Calculate right max heights
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], h[i]);
        }
        
        // Calculate the total trapped water
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - h[i];
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Sample input: heights of bars
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    // Calling the trap function
    int result = solution.trap(heights);
    
    // Output the result
    cout << "Trapped water: " << result << endl;
    
    return 0;
}
