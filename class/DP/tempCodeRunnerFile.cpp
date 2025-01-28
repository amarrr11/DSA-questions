#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &x:v){
            cin>>x;
        } 
        int even=0,odd=0;
        for(int &i:v){
            if(i&1) odd++;
            else even=1;
        }
        if(even){
            cout<<even+odd<<endl;
        }else{
            cout<<odd-1<<endl;
        }
        
    }
}