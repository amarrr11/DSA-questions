/*Sorting Elements of an Array by Frequency

Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency
comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the 
smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have 
the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array according to the frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (mp[a] == mp[b]) {
                return a < b; // Sort by value if frequencies are the same
            }
            return mp[a] > mp[b]; // Sort by frequency
        });
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 3, 5, 2, 8, 2, 8, 8};
    
    vector<int> sortedArr = sol.sortByFreq(arr);
    
    cout << "Sorted array by frequency: ";
    for (int i : sortedArr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
