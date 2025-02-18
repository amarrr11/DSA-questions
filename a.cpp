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
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(auto &x:a){
        cin>>x;
    }
    for(auto &x:b){
        cin>>x;
    }
    
    if(b[0]-a[0]<a[0]){
        a[0]=b[0]-a[0];
    }

    for(int i=1;i<n-1;i++){
        if(b[0]-a[i]<a[i] and b[0]-a[i]>=a[i-1] and b[0]-a[i]<=a[i+1]){
            a[i]=b[0]-a[i];
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    // Uncomment the following lines if multiple test cases are intended
    cin >> testcase;
    while (testcase--) {
       Amar();
    }
    return 0;
}
