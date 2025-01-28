/*Given array find maximum/longest bitonic subsequence*/

#include<bits/stdc++.h>
using namespace std;

// Function to find the longest increasing subsequence
int solve(vector<int> &nums, int idx, int prev) {
    if (idx >= nums.size()) {
        return 0;
    }

    int exclude = solve(nums, idx + 1, prev);
    int include = 0;
    if (prev == -1 || nums[idx] > prev) {
        include = 1 + solve(nums, idx + 1, nums[idx]);
    }

    return max(include, exclude);
}

// Function to find the longest decreasing subsequence
int solve1(vector<int> &nums, int idx, int prev) {
    if (idx >= nums.size()) {
        return 0;
    }
    int exclude = solve1(nums, idx + 1, prev);
    int include = 0;
    if (prev == -1 || nums[idx] < prev) {
        include = 1 + solve1(nums, idx + 1, nums[idx]);
    }
    return max(include, exclude);
}

// Main function
int main() {
    vector<int> v = {3, 2, 1, 5, 4};
    
    int maxBitonic = 0;
    
    // Try each element as the peak of the bitonic subsequence
    for (int i = 0; i < v.size(); ++i) {
        int inc = solve(v, 0, -1);
        int dec = solve1(v, i + 1, -1);
        maxBitonic = max(maxBitonic, inc + dec - 1); // subtract 1 to avoid double counting the peak element
    }
    
    cout << maxBitonic << endl;
}
