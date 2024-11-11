#include <bits/stdc++.h>

#define loop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(r); i >= (int)(l); --i)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pp;
typedef vector<pp> vpp;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef pair<ll, ll> pll;
typedef unordered_map<int, vi> uG;
typedef unordered_map<int, vpp> wG;

const int inf = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

void Amar() {
    ll l,r,k;
    cin>>l>>r>>k;

    vector<ll> v;
    for(int i=l;i<=r;i++){
        v.push_back(i);
    }
    
    ll maxi=r;
    ll ans=0;
    for(ll i:v){
        ll k1=k;
        for(ll j=i;j<=maxi;j+=i){
            if(j<=r){
                k1--;
            }
            if(k1==0){
                
                ans++;
                break;
            }
        }
    }
    cout<<ans<<'\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    while (testcase--) {
       Amar();
    }
    return 0;
}