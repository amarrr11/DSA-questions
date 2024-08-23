#include <bits/stdc++.h>
using namespace std ;

//in n2 

// bool isprime(int n){
//     if(n<=1){
//         return false;
//     }
//     for(int i=2;i<n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

//in sqrt(n)
// bool isprime(int n){
//     if(n<=1){
//         return false;
//     }
//     for(int i=2;i*i<n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

bool isprime(int n){
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
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"Prime"<<endl;
    }else{
        cout<<"Not prime"<<endl;
    }
    return 0;
}