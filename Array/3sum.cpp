/*15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            int n=nums.size();
            for(int i=0;i<nums.size();i++){
                if(i>0 and nums[i-1]==nums[i]) continue;
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
    
                    if(sum<0){
                        j++;
                    }else if(sum>0){
                        k--;
                    }else{
                        vector<int>v={nums[i],nums[j],nums[k]};
                        ans.push_back(v);
                        j++;
                        k--;
                        while(j<k and nums[j]==nums[j-1]) j++;
                        while(j<k and nums[k]==nums[k+1]) k--;
                    }
                }
            }
            return ans;
    
        }
    };

int main() {
    Solution sol;
    
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<vector<int>> result = sol.threeSum(nums);
    
    // Printing the output
    cout << "Triplets forming sum 0 are:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
