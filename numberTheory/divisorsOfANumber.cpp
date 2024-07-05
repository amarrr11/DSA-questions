/*
Print all Divisors of a number

Given an integer ‘N’, your task is to write a program that returns all the divisors of ‘N’ in ascending order.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int* printDivisors(int n, int &size) {
    int* ans = new int[10000];
    int j = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans[j++] = i;
            size++;
            if (i != n / i) {
                ans[j++] = n / i;
                size++;
            }
        }
    }
    sort(ans, ans + size);
    return ans;
}

//2

 // vector<int> ans;
    // for(int i=1;i<=n;i++){
    //     if(n%i==0){
    //         ans.push_back(i);
    //     }
    // }
    // size=ans.size();
    // int* res=new int[size];
    // for(int i=0;i<size;i++){
    //     res[i]=ans[i];
    // }
    // return res;
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int size = 0;
    int* divisors = printDivisors(n, size);

    cout << "Divisors of " << n << " are: ";
    for (int i = 0; i < size; i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;

    delete[] divisors;

    return 0;
}
