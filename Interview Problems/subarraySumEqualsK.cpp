/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution 
public:
    int subarraySum(vector<int>& nums, int k) 
        int total=0;
        int n=nums.size();
        map< int, int> m;
        int sum=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-k) != m.end()){
                total+=m[sum-k];
                m[sum]++;
            }
            else{
                m[sum]++;
            }
        }
        return total;
    
;

int main() {
    Solution sol;
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int k;
    cout << "Enter the target sum (k): ";
    cin >> k;

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum equal to " << k << ": " << result << endl;

    return 0;
}
