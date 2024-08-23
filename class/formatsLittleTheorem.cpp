//if p is a prime number and a is a +ve integer not divisible by p such that a^(p-1)~=1(mod p).Prova formats theorem
//7,3

#include<bits/stdc++.h>
using namespace std;
bool isprime(long long n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 or n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 or n%(i+2)==0){
            return false;
        }
    }
    return true;
}
int main(){
    long long p,a;
    cin>>p>>a;
    if(isprime(p) and (p%a)!=0){
        long long power=pow(a,p-1);
        if(power%p==1){
            cout<<"TRUE"<<endl;
            return 0;
        }
    }
    cout<<"FALSE"<<endl;
    return 0;
}