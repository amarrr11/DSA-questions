/*Max sum path in two arrays

Difficulty: Medium
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. 
Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another
 array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.

Examples : 

Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
Output: 35
Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 
10 and 12.
Input: arr1 = [1, 2, 3] , arr2[] = [3, 4, 5]
Output: 15
Explanation: The path will be 1+2+3+4+5=15.*/

#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
    int m = arr1.size();
    int n = arr2.size();
    
    int i = 0, j = 0;
    int ans = 0;
    int s1 = 0, s2 = 0;
    
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            ans += max(s1, s2) + arr1[i];
            s1 = 0;
            s2 = 0;
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) {
            s2 += arr2[j++];
        } else {
            s1 += arr1[i++];
        }
    }
    
    while (i < m) {
        s1 += arr1[i++];
    }
    while (j < n) {
        s2 += arr2[j++];
    }
    
    ans += max(s1, s2);
    return ans;
}

int main() {
    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};

    int result = maxPathSum(arr1, arr2);
    
    cout << "The maximum path sum is: " << result << endl;

    return 0;
}
