/*Subset Sums
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Example 1:

Input:
n = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

Example 2:

Input:
n = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(vector<int> &arr, int n, vector<int> &ans, int sum, int i) {
        if (i == n) {
            ans.push_back(sum);
            return;
        }

        solve(arr, n, ans, sum + arr[i], i + 1);
        solve(arr, n, ans, sum, i + 1);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        solve(arr, n, ans, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2};
    int n = arr.size();
    
    vector<int> result = sol.subsetSums(arr, n);
    
    cout << "Subset sums: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    // Additional example
    vector<int> arr2 = {5, 2, 1};
    n = arr2.size();
    
    result = sol.subsetSums(arr2, n);
    
    cout << "Subset sums: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
