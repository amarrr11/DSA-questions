// Product Of Array Except Self
// Problem statement
// You have been given an integer array/list (ARR) of size N. You have to return an array/list PRODUCT such that PRODUCT[i] is equal to the product of all the elements of ARR except ARR[i]

// Note :
// Each product can cross the integer limits, so we should take modulo of the operation. 

// Take MOD = 10^9 + 7 to always stay in the limits.
// Follow up :
// // Can you try solving the problem in O(1) space?
// Test case 1 : Given array = {1, 2, 3] 
//  Required array = [2 * 3, 1 * 3, 1 * 2] = [6, 3, 2]
//  Test case 2 : Given array = {5, 2, 2] 
//  Required array = [2 * 2, 5 * 2, 5 * 2] = [4, 10, 10]

#include <iostream>

using namespace std;

int *getProductArrayExceptSelf(int *arr, int n) {
    if (n < 1) {
        return nullptr; // Returning nullptr to indicate invalid input
    }
    int *left = new int[n];
    int *right = new int[n];
    int *ans = new int[n];
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = (1LL * left[i - 1] * arr[i - 1]) % 1000000007;
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = (1LL * right[i + 1] * arr[i + 1]) % 1000000007;
    }
    for (int i = 0; i < n; i++) {
        ans[i] = (1LL * left[i] * right[i]) % 1000000007;
    }
    
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int *result = getProductArrayExceptSelf(arr, n);
    
    cout << "Product Array Except Self: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // Freeing memory allocated by getProductArrayExceptSelf function
    delete[] result;
    
    return 0;
}
