/*Subset Sum Problem

Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum 
equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2, target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.*/


#include <iostream>
#include <vector>
using namespace std;

public:
    // vector<vector<int>> dp;
    
    bool solve(vector<int>& arr, int target, int idx) {
        // Base case: if the target sum becomes 0, it means we found a subset with the sum
        if (target == 0) {
            return true;
        }
        
        
        if (idx >= arr.size() || target < 0) {
            return false;
        }

        // if(dp[target][idx] != -1) return dp[target][idx]; 
        // return dp[target][idx] = solve(arr, target - arr[idx], idx + 1) || solve(arr, target, idx + 1);

        return solve(arr, target - arr[idx], idx + 1) || solve(arr, target, idx + 1);
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        // dp = vector<vector<int>>(target + 1, vector<int>(arr.size(), -1)); // Initialize dp table
        return solve(arr, target, 0);
    }

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2}; // Example array
    int target = 9; // Example target sum
    
    // Create an instance of the class and call the isSubsetSum function
    YourClass obj;  // Replace "YourClass" with the actual class name that contains the methods
    if (obj.isSubsetSum(arr, target)) {
        cout << "Subset with given sum exists!" << endl;
    } else {
        cout << "Subset with given sum does not exist!" << endl;
    }

    return 0;
}
