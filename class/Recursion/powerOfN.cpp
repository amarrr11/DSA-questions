#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){
    if(b==1) {
        return a;
    } 
    return a* solve(a,b-1);
}

int pow1(int a,int n){
    int res=1;
    while(n){
        if(n&1){
            res*=a;
        }
        n=n>>1;
        a*=a;
    }
    return res;
}
int pow(int a,int n){
    if(n==0){
        return 1;
    }
    int res=pow(a,n/2);
    if(n&1){
        return a*res*res;
    }
    return res*res;
}

int main(){
    int a=2;
    int b=3;

    cout<<pow(a,b)<<endl;
}