
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    long long ans=1;
    long long mod=1000000007;
    while(b>0){
        if(b&1){  
            ans=(ans*(a%mod))%mod;
        }
        a=((a%mod)*(a%mod))%mod;
        b=b>>1;
    }
    cout<<ans;
    return 0;
}