/*1524. Number of Sub-arrays With Odd Sum

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int cnt=0;
        // void solve(vector<int> &v,int idx,int n){
        //     for(int i=idx;i<n;i++){
        //         int temp=v[i]-idx;
        //         if(temp%2!=0) cnt++;
        //     }
        // }
        int numOfSubarrays(vector<int>& arr) {
            int M=1e9+7;
            int n=arr.size(); 
            vector<int> v(n);
            int sum = 0;
            // Compute prefix sum array
            for (int i = 0; i < n; i++) {
                sum += arr[i];
                v[i] = sum;
            }
            int even=1;
            int odd=0;
            for(int i=0;i<n;i++){
                if(v[i]%2==0){
                    cnt=(cnt+odd)%M;
                    even++;
                }else{
                    cnt=(cnt+even)%M;
                    odd++;
                }
            }
    
            return cnt;
        }
    };

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5}; // Example input
    cout << sol.numOfSubarrays(arr) << endl;
    return 0;
}
