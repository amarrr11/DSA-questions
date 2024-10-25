// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(auto &x:v){
            cin>>x;
        }
        unordered_map<ll,ll> mp;
        mp[0]=1;
        ll sum=0;
        ll ans=0;
        for(ll i:v){
            sum+=i;
            if(sum==0){
                ans++;
                continue;
            }
            mp[sum]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}