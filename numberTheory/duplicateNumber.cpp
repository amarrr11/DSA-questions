/*
287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;

        // map<int,int> m;
        // int n=nums.size();
        // int j=0;
        // for(int i=0;i<n;i++){
        //     if(m[nums[i]]) return nums[i];
        //     m[nums[i]]++;
        // }
        // return 0;
        
        //sum of natutral numbers - total sum

        /*xor cannot solve cause not only 2 times repeating
    
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=ans^arr[i];
        }
        for(int i=1;i<arr.size();i++){
            ans^=i;
        }
        return ans;*/
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = solution.findDuplicate(nums);
    cout << "Duplicate number: " << duplicate << endl;

    return 0;
}
