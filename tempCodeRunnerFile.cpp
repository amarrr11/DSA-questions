// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {

    long long n;
    cin>>n;
    
    vector<long long> v;
    for(long long i=1;i<=n;i++){
        v.push_back(i);
    }

    long long sum = 1LL * n * (n + 1) / 2;
    
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    
    vector<long long > arr;
    vector<long long> arr2;
    
    long long num=sum/2;
    
    long long s=0;
   
    for(long long i=n-1;i>=0;i--){
        if(s+v[i]>num){
            i--;
        }else{
            s+=v[i];
            arr.push_back(v[i]);
            v[i]=-1;
        }
    }

    for(long long i=0;i<n;i++){
        if(v[i]!=-1){
            arr2.push_back(v[i]);
        }
    }

       cout<<arr.size()<<endl;
       for(long long i=0;i<arr.size();i++){
           cout<<arr[i]<<" ";
       }
       cout<<endl;
       cout<<arr2.size()<<endl;
       for(long long i:arr2){
           cout<<i<<" ";
       }
       cout<<endl;

    

    return 0;
}