/*930. Binary Subarrays With Sum(Same as subarray with sum k)

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

/*There are two ways: first ki make unoredred map and store each sum of each subarray while we transverse and store the sum in map
with its count , then if sum-k will be present it means there is desired sum present and count plus 1.
Another way is sliding window: We will find subarrays with sum<=goal and the subtract sum<=goal-1 , so we get sum=goal subarrays.
*/
/*
Explanation of the Map Method
Prefix Sum Concept:

The prefix sum up to index i is the sum of all elements from the start of the array up to index i.
If we know the prefix sum up to two different indices, say i and j, we can find the sum of the subarray from i+1 to j by subtracting the prefix sum up to i from the prefix sum up to j.
Key Insight:

To find a subarray with a sum equal to goal, we need to track the prefix sums and their frequencies.
If the current prefix sum is sum, we want to find out how many times the prefix sum sum - goal has occurred before. This is because if sum[j] - sum[i] = goal, then sum[i] = sum[j] - goal.
Map Utilization:

We use an unordered map m to store the frequency of each prefix sum.
m[0] = 1 initializes the map with the base case: a prefix sum of 0 has occurred once before we start iterating over the array.
Iterating Through the Array:

As we iterate through the array, we maintain a running prefix sum sum.
For each element in the array, we add its value to sum.
We then check if sum - goal exists in the map. If it does, it means there is a subarray ending at the current index with the sum equal to goal. The value of m[sum - goal] gives the number of such subarrays.
We update the count cnt by adding the frequency of sum - goal found in the map.
We then increment the frequency of the current prefix sum sum in the map.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> m; // Map to store prefix sum frequencies
    m[0] = 1; // There is one way to have a prefix sum of 0 (an empty subarray)
    int cnt = 0; // Count of subarrays with sum equal to goal
    int sum = 0; // Current prefix sum
    int n = nums.size();
    
    for (int j = 0; j < n; ++j) {
        sum += nums[j]; // Update the current prefix sum
        if (m.find(sum - goal) != m.end()) {
            cnt += m[sum - goal]; // Add the frequency of (sum - goal) to the count
        }
        m[sum]++; // Increment the frequency of the current prefix sum
    }
    
    return cnt; // Return the total count of subarrays with sum equal to goal
}

    /*
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> m; // Map to store prefix sum frequencies
    m[0] = 1; // There is one way to have a prefix sum of 0 (an empty subarray)
    int cnt = 0; // Count of subarrays with sum equal to goal
    int sum = 0; // Current prefix sum
    int n = nums.size();
    
    for (int j = 0; j < n; ++j) {
        sum += nums[j]; // Update the current prefix sum
        if (m.find(sum - goal) != m.end()) {
            cnt += m[sum - goal]; // Add the frequency of (sum - goal) to the count
        }
        m[sum]++; // Increment the frequency of the current prefix sum
    }
    
    return cnt; // Return the total count of subarrays with sum equal to goal
}
    */

    // int atMost(vector<int> nums, int goal){
    //     int l=0, r=0, count=0, sum=0;
    //     while(r < nums.size()){
    //         if(goal < 0) return 0;
    //         sum += nums[r];
    //         while(sum > goal){
    //             sum -= nums[l];
    //             l++;
    //         }
    //         count += (r - l + 1);
    //         r++;
    //     }
    //     return count;
    // }
    
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     return atMost(nums, goal) - atMost(nums, goal - 1);
    // }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = solution.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum " << goal << " is: " << result << endl;
    return 0;
}
