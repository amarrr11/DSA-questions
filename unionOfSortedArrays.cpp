//Problem statement
// Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, return the union of the arrays.



// The union of two sorted arrays can be defined as an array consisting of the common and the distinct elements of the two arrays. The final array should be sorted in ascending order.



// Note: 'a' and 'b' may contain duplicate elements, but the union array must contain unique elements.



// Example:
// Input: ‘n’ = 5 ‘m’ = 3
// ‘a’ = [1, 2, 3, 4, 6]
// ‘b’ = [2, 3, 5]

// Output: [1, 2, 3, 4, 5, 6]

// Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
// Distinct elements in ‘a’ are: [1, 4, 6]
// Distinct elements in ‘b’ are: [5]
// Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]


#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    // Make an answer vector
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    
    // Merge the two sorted arrays
    while (i < n && j < m) { 
        if (a[i] <= b[j]) { 
            // Add element from array a to ans if it's smaller or equal
            if (ans.size() == 0 || ans.back() != a[i]) { 
                // Ensure no duplicate elements are added
                ans.push_back(a[i]);
            }
            i++;
        } else {
            // Add element from array b to ans if it's smaller
            if (ans.size() == 0 || ans.back() != b[j]) { 
                // Ensure no duplicate elements are added
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    
    // Add remaining elements of array a
    while (i < n) { 
        if (ans.size() == 0 || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }
    
    // Add remaining elements of array b
    while (j < m) { 
        if (ans.size() == 0 || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    
    return ans;
}

int main() {
    // Input arrays
    vector<int> a, b;
    int n, m;
    
    // Get the size of array a from the user
    cout << "Enter the size of array a: ";
    cin >> n;
    // Input elements of array a
    cout << "Enter the elements of array a: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    // Get the size of array b from the user
    cout << "Enter the size of array b: ";
    cin >> m;
    // Input elements of array b
    cout << "Enter the elements of array b: ";
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        b.push_back(num);
    }
    
    // Call sortedArray function
    vector<int> merged = sortedArray(a, b);
    
    // Output the merged array
    cout << "Merged Array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
