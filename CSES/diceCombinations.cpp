#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
long long solve(int n,vector<int> &v){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    long long sum=0;
    for(int i=1;i<=6;i++){
        sum+=solve(n-i,v);
    }
    return dp[n]=sum%1000000007;
}

int main(){
    int n;
    cin>>n; 
    dp.resize(10000005,-1);
    vector<int> v(6);
    for(int i=0;i<6;i++){
        v[i]=i+1;
    }
    cout<<solve(n,v)<<'\n';
}