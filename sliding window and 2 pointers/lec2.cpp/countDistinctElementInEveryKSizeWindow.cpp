/*
Count Distinct Element in Every K Size Window

You are given an array ‘ARR’ of size ‘N’ and an integer ‘K’. Your task is to find the total number of distinct elements 
present in every ‘K’ sized window of the array. A ‘K’ sized window can also be viewed as a series of continuous ‘K’ elements
present in the sequence.

Note:
1. The size of ‘ARR’ will always be greater than or equal to the ‘K’.
2. Here window refers to a subarray of ‘ARR’. Hence ‘K’ sized window means a subarray of size ‘K’.
3. return an array of the count of all distinct elements in the ‘K’ size window.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i = 0; i < k; i++){
        m[arr[i]]++;
    }
    ans.push_back(m.size());
    for(int i = k; i < n; i++){
        if(m[arr[i - k]] == 1){
            m.erase(arr[i - k]);
        } else {
            m[arr[i - k]]--;
        }

        m[arr[i]]++;
        ans.push_back(m.size());
    }
    return ans;
}

/* This commented-out section provides alternative ways to count distinct elements in subarrays of size k.
for(int i = 0; i <= (n - k); i++){
    for(int j = i; j < (i + k); j++){
        s.insert(arr[j]);
    }
    ans.push_back(s.size());
    s.clear();
}

for(int i = 0; i <= (n - k); i++){
    for(int j = i; j < (i + k); j++){
        if(m[arr[j]]){
            continue;
        } else {
            m[arr[j]]++;
        }
    }
    ans.push_back(m.size());
    m.clear();
}

return ans;
*/

int main() {
    // Example 1
    vector<int> arr1 = {1, 2, 1, 3, 4, 2, 3};
    int k1 = 4;
    vector<int> result1 = countDistinctElements(arr1, k1);
    cout << "Distinct elements in each subarray of size " << k1 << " are: ";
    for(int x : result1) {
        cout << x << " ";
    }
    cout << endl;

    // Example 2
    vector<int> arr2 = {1, 2, 4, 4, 5, 6, 4};
    int k2 = 3;
    vector<int> result2 = countDistinctElements(arr2, k2);
    cout << "Distinct elements in each subarray of size " << k2 << " are: ";
    for(int x : result2) {
        cout << x << " ";
    }
    cout << endl;

    // Example 3
    vector<int> arr3 = {1, 1, 1, 1, 1};
    int k3 = 2;
    vector<int> result3 = countDistinctElements(arr3, k3);
    cout << "Distinct elements in each subarray of size " << k3 << " are: ";
    for(int x : result3) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
