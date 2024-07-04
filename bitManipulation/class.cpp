
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
    //divisors
    // int n;
    // cin>>n;
    // for(int i=1;i*i<n;i++){
    //     if(n%i==0){
    //         cout<<i<<" ";
    //     }
    //     if(n%(n/i)==0){ (if(i!=n/i))
    //         cout<<(n/i)<<" ";
    //     }
    // } 
    // TC?
    
    //prime number
    // int n;
    // cin>>n;
    // bool flag=false;
    // for(int i=2;i*i<n;i++){
    //     if(n%i==0) flag=true;
    // }
    // if(flag==false){
    //     cout<<"prime";
    //     return 0;
    // }
    // cout<<"not prime"<<" ";
    
    //prime factors
    // int n;
    // cin>>n;
    // for(int i=2;i*i<=n;i++){
    //     while(n%i==0){
    //         cout<<i<<" " ;
    //         n/=i;
    //     }
    // }
    // if(n>1) cout<<n<<" ";
    
    //is perfect square?
    // int n;
    // cin>>n;
    //1
    // for(int i=1;i*i<=n;i++){
    //     if((i*i)==n) {
    //         cout<<"yes perfect square of "<< i <<" .";
    //         return 0;
    //     }
    // } 
    // cout<<"no"<<" ";
    
    //2 tc = ?
    // int d=sqrt(n);
    // if(d*d==n){
    //     cout<<"yes";
    // }else{
    //     cout<<" no";
    // }
    
    //3: binary serach
    
    //4. No of divisors = odd;
    // int cnt=0;
    // for(int i=1;i*i<=n;i++){
    //     if(n%i==0){
    //         cnt++;
        
    //         if(i!=(n/i)){
    //             cnt++;
    //     }}
    // } 
    // if(cnt%2==0) cout<<"not square root";
    // else cout<<"yes square root";
    
    ///5 : sum of n odd natural numbers = n^2;

    //prime factorization : TC:nloglogn
    // vector<bool> isprime(n+1,true);
    // for(int i=2;i<=n;i++){
    //     if(isprime[i]){
    //         cout<<i<<" ";
    //         for(int j=2*i;j<=n;j+=i){
    //             isprime[j]=false;
    //         }
    //     }
    // }

    /*TC:nlogn
    vector<bool> isprime(n+1,true);
    for(int i=2;i<=n;i++){
       
            for(int j=2*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    
    for(int i=2;i<n;i++){
        if(isprime[i]) cout<<i<<" ";
    }
    */

//     return 0;

// }

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int countDiv(int n,map<int,int> m){
    int cnt=1;
    for(auto it:m){
        cnt*=it.second+1;
    }
    return cnt;
}

int main() {
    
    //count of divisors
    //sum of divisors
    //product of divisors

    int n;
    cin>>n
    map<int,int> m;
    
    for(int i=0;i<n;i++){
        m[fac[i]]++;
    }
    cout<<countDiv(36,m);
    


    return 0;
}    d