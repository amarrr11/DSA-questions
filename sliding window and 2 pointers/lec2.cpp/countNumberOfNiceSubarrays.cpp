/*
1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        unordered_map<int, int> m;
        m[0] = 1;
        int j = 0;
        long long int ans = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            if (m[sum - k]) {
                ans += m[sum - k];
            }
            m[sum]++;
            j++;
        }
        return ans;
    }

    // int atMost(vector<int> & nums, int k){
    //     int i=0, j=0, cnt=0, sum=0;
    //     while(j < nums.size()){
    //         if(k < 0) return 0;
    //         sum += nums[j];
    //         while(sum > k){
    //             sum -= nums[i];
    //             i++;
    //         }
    //         cnt += j - i + 1;
    //         j++;
    //     }
    //     return cnt;
    // }
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] % 2 == 0) {
    //             nums[i] = 0;
    //         } else {
    //             nums[i] = 1;
    //         }
    //     }
    //     return atMost(nums, k) - atMost(nums, k - 1);
    // }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    int result = solution.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with " << k << " odd numbers is: " << result << endl;
    return 0;
}
