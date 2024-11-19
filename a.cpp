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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    vector<pair<int,int>> v ;
    for(int i=0;i<n;i++){
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());

    for(auto &it:v){
        
        int f=it.first;
        int s=it.second;

        ans[s]=f/b[s];
        k-=ans[s];
    }
    vector<int> ans(n);
    if(k>0){
        for(int i=0;i<n;i++){
            cout<<0<<" ";
        }
    }else{
        for(int i:ans){
            cout<<i<<endl;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    // Uncomment the following lines if multiple test cases are intended
    // cin >> testcase;
    // while (testcase--) {
       Amar();
    // }
    return 0;
}
