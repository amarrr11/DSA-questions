// Problem statement
// Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping the non-zero elements at the start of the array in their original order. Return the modified array.



// Example :
// Input: ‘n’ = 5, ‘arr’ = [1, 2, 0, 0, 2, 3]
// Output: [1, 2, 2, 3, 0, 0]

// Explanation: Moved all the 0’s to the end of an array, and the rest of the elements retain the order at the start.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> moveZeros(int n, vector<int> &arr) {
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        return arr;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
}

int main() {
    vector<int> arr = { 1, 0, 3, 12,0,21,223,0,21};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> movedArr = moveZeros(arr.size(), arr);

    cout << "Array after moving zeros to the end: ";
    for (int num : movedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
