#include<bits/stdc++.h>
using namespace std;
int main(){
    //all prime factors of the given array elements
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m=*max_element(arr.begin(),arr.end());
    vector<int> lpf(m,-1);
    vector<int> prime(m,1);



}