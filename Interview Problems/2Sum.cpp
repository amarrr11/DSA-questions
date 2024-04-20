// Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution { //BRUTE FORCE
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
//if asked only yes or no then we can sort the array first and then we will keep two pointers at left and right and check it the sum of left +right 
//index will be target , if the sum is less than target then increase the left pointer else inc the right pointer.THIS WONT WORK IF INDEX ARE ASKED.
string read(int n, vector<int> book, int target)
{
    sort(book.begin(),book.end());
    int left=0;
    int right=n-1;
    while(left<right){
        
        if(book[left]+book[right]==target){
            return "YES";
        }
        else if(book[left]+book[right]<target){
            left++;
        }
        else{
            right--;
        }

    }
    return "NO";
}



int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    if (result.size() == 2) {
        cout << "Indices of the two numbers whose sum is equal to target: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No such pair found." << endl;
    }
    
    return 0;
}
