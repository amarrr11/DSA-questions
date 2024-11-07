#include<bits/stdc++.h>
using namespace std;

vector<int> getDigits(int n){
    vector<int> v;
    while(n>0){
        if(n%10!=0){
            v.push_back(n%10);
        }
        n/=10;
    }
    return v;
}
vector<int> dp;
int solve(int n){

    if(n==0) return 0;
    if(n<=9) return 1;
    int result=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    vector<int> temp=getDigits(n);
    for(int i=0;i<temp.size();i++){
        result=min(result,solve(n-temp[i]));
    }
    return dp[n]=1+result;
}

int main(){
    int n;
    cin>>n;
    dp.resize(1000005,-1);
    cout<<solve(n)<<'\n';
    return 0;
}