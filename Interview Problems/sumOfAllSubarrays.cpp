#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i]*(n-i)*(i+1);
    }
    cout<<"the sum of all the subarrays is: "<<sum<<endl;

    return 0;
}