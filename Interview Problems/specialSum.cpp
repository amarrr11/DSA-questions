/*Problem statement
You are given an array ‘ARR’ of length ‘N’. There are two operations, ‘FIRST_SUM’ and ‘LAST_SUM’ for every index ‘i’ 
(1 <= i <= N) in the array,

i) FIRST_SUM(i) calculates the sum of first i numbers.

ii) LAST_SUM(i) calculates the sum of last N-i+1 numbers.

Also for every ‘i’, SPECIAL_SUM(i) can be calculated as:

SPECIAL_SUM(i) = FIRST_SUM(i) + LAST_SUM(i)

Your task is to return the minimum SPECIAL_SUM for 0 <= i <= N - 1.

For example:

Given ‘N’ = 4 and ‘ARR’ = [1, 2, 3, 4].
Then the minimum special sum will be 5 for i = 0 (0-based indexing), which is (1 + 4) = 5.Sum of 1 integer from beginning 
and end.
For i = 1 it will be (1 + 2) + (3 + 4) = 10
For i = 2 it will be (1 + 2 + 3) + (2 + 3 + 4) = 15
For i = 3 it will be (1 + 2 + 3 + 4) + (1 + 2 + 3 + 4) = 20
All of which are greater than 5.  */

#include <bits/stdc++.h>
using namespace std;

int specialSum(vector<int> &arr, int n)
{
    /*
    int sum=0;
    
    vector<int> prefix(n,0);
    vector<int> suffix(n,0);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
    reverse(suffix.begin(),suffix.end());
    int finalSum=INT_MAX;
    for(int i=0;i<n;i++){
        sum=prefix[i]+suffix[i];
        finalSum=min(finalSum,sum);
    }
    return finalSum;
    */
    

    int finalSum = INT_MAX;
    int firstSum = 0;
    int lastSum = 0;
    int specialSum = 0;
    for(int i = 0; i < n; i++) {
        firstSum += arr[i];
        lastSum += arr[n - i - 1];
        specialSum = firstSum + lastSum;
        finalSum = min(finalSum, specialSum);
    }
    return finalSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = specialSum(arr, n);
    cout << "The special sum is: " << result << endl;

    return 0;
}
