// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> v(n);
        for(auto &x:v){
            cin>>x;
        }
        long long m=-1;
        long long ans=0;
        for(long long i=1;i<n;i++){
            if(v[i]>v[i-1]){
                m=v[i];
                break;
            }
        }
        if(m==-1){
            cout<<0<<endl;
            continue;
        }
        for(long long i=1;i<n;i++){
            if(v[i]>=m){
                ans++;
                m=v[i];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}