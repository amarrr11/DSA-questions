/*
Allocate Books

Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.
Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
*/

#include <bits/stdc++.h>
using namespace std;

int cntStudent(vector<int> &arr, int pages) {
    int cnt = 0, sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum <= pages) {
            continue;
        } else {
            cnt++;
            sum = arr[i];
        }
    }
    cnt++;
    return cnt;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for(int num : arr) {
        sum += num;
    }
    int res = -1;
    int high = sum;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int temp = cntStudent(arr, mid);
        if(temp > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        res = low;
    }
    if(res == 0) {
        return -1;
    }
    return res;
}

int main() {
    // Example 1
    vector<int> arr1 = {12, 34, 67, 90};
    int n1 = arr1.size();
    int m1 = 2;
    int result1 = findPages(arr1, n1, m1);
    cout << "Minimum number of pages: " << result1 << endl;

    // Example 2
    vector<int> arr2 = {10, 20, 30, 40};
    int n2 = arr2.size();
    int m2 = 2;
    int result2 = findPages(arr2, n2, m2);
    cout << "Minimum number of pages: " << result2 << endl;

    // Example 3
    vector<int> arr3 = {5, 17, 100, 11};
    int n3 = arr3.size();
    int m3 = 4;
    int result3 = findPages(arr3, n3, m3);
    cout << "Minimum number of pages: " << result3 << endl;

    return 0;
}
