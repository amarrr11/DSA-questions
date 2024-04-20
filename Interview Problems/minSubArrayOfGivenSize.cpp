// Minimum Sum Subarray Of Given Size
// Problem statement
// You have been given an array 'ARR' of integers consisting of ‘N’ integers and a positive integer ‘K’. Your task is to find a subarray(contiguous) of size ‘K’ such that the sum of its elements is minimum.

// Note :
// You can assume that the value of ‘K’ will always be less than or equal to ‘N’. So, the answer will always exist.
// Sample Input 1 :
// 8 3
// 10 4 2 5 6 3 8 1
// Sample Output 1 :
// 11
// Explanation Of Sample Input
// All subarrays of size 3 and their respective sums are-
// {10, 4, 1} : sum → 10+4+1 = 15
// {4, 2, 5} : sum → 4+2+5 = 11
// {2, 5, 6} : sum → 2+5+6 = 13
// {5, 6, 3} : sum → 5+6+3 = 14
// {6, 3, 8} : sum → 6+3+8 = 17
// {3, 8, 1} : sum → 3+8+1 = 12

// The subarray with a minimum sum of 11 is {4, 2, 5}.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubarraySum(int arr[], int n, int k) 
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n - k + 1; i++) {
        sum = 0; // Reset sum for each new subarray
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    
    return ans[0];
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = minSubarraySum(arr, n, k);
    cout << "Minimum subarray sum of size " << k << " is: " << result << endl;

    return 0;
}
