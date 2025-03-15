/*2226. Maximum Candies Allocated to K Children

You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.

 

Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        typedef long long ll;
        ll solve(vector<int> &v, long long mid){
            ll kids=0;
            for(int i=0;i<v.size();i++){
                kids+=v[i]/mid;
            }
            return kids;
        }
        int maximumCandies(vector<int>& v, long long k) {
            ll totalCandies = 0;
            for (int i = 0; i < v.size(); i++) {
                totalCandies += v[i];
            }
            
            // If total candies are less than kids, return 0 (impossible to distribute)
            if (totalCandies < k) return 0;
            ll n=v.size();
            int ans=0;
            ll low=1;
            ll high=*max_element(v.begin(),v.end());
            while(low<=high){
                
                ll mid = low + (high - low) / 2;
                ll kids=solve(v,mid);
                if(kids>=k){
                    ans=mid;
                    low=mid+1;
                }else if(kids<k){
                    high=mid-1;
                }
            }
            return ans;
        }
    };


int main() {
    Solution sol;
    
    // Example input
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    // Function call
    int result = sol.maximumCandies(candies, k);

    // Output the result
    cout << "Maximum candy size: " << result << endl;

    return 0;
}
