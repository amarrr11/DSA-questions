/*40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates
 where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]*/

#include <bits/stdc++.h>
using namespace std;    

class Solution {
    public:
        vector<vector<int>> ans;
        // map<int,int> mp;
        void solve(vector<int> &nums,vector<int> &temp,int target,int idx){
            if(target==0){
                ans.push_back(temp);
                return;
            }
            if(target<0 ){
                return;
            }
    
            for(int i=idx;i<nums.size();i++){
                
                if(i>idx and nums[i]==nums[i-1]) continue;
                if(nums[i]<=target){
                    temp.push_back(nums[i]);
                    solve(nums,temp,target-nums[i],i+1);
                    temp.pop_back();
                }
                
            }
        }
        // void solve(vector<int> &nums,vector<int> &temp,int target,auto itr){
        //     if(target==0){
        //         ans.push_back(temp);
        //         return;
        //     }
        //     if(target<0 ){
        //         return;
        //     }
    
        //     // for(auto &it:mp){
        //     for(auto it = itr; it != mp.end(); ++it) {
        //         if(it->second>0 and it->first<=target){
        //             it->second--;
        //             temp.push_back(it->first);
        //             solve(nums,temp,target-it->first,it);
        //             temp.pop_back();
        //             it->second++;
        //         }
        //     }
        // }
    
        vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
            int n=nums.size();
            vector<int> temp;
            sort(nums.begin(),nums.end());
            // mp.clear();
            // for(int i:nums) mp[i]++;
            // solve(nums,temp,target,mp.begin());
            solve(nums,temp,target,0);
            return ans;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    
    vector<vector<int>> result = sol.combinationSum2(nums, target);
    
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto &vec : result) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
