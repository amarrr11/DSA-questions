#include<bits/stdc++.h>
using namespace std;

int hcf(int a,int b){ //O(min(a,b))
    for(int i=min(a,b);i>2;i--){
        if(a%i==0 and b%i==0) return i;
    }
    return -1;
}

int gcd(int a,int b){  //TC : O(log(a,b))
    if(a==0) return b;

    return gcd(b%a,a); //even if gcd(27%45,27)
}

int main(){
    int a=222;
    int b=34;

    cout<<gcd(a,b); 
}