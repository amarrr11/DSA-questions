#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m1=0,m2=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i+=2){
        m1+=v[i];
        cnt1++;
    }
    for(int i=1;i<n;i+=2){
        m2+=v[i];
        cnt2++;
    }

    if(m1>m2){
        cout<<m1+cnt1<<endl;
    }else{
        cout<<m2+cnt2<<endl;
    }
}