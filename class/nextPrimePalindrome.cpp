
#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n==0 or n==1) return 0;
    if(n<=3) return true;
    if(n%2==0 or n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 or n%(i+2)==0) return false;
    }
    return true;
}

bool palindrome(int st){
    string s=to_string(st);
    int n=s.size();
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    
    int n;
    cin>>n;
    int i=n;
    while(true){
        if(prime(i) and palindrome(i)){
            cout<<i<<endl;
            break;
        }
        i++;
    }

    return 0;
}
// chi and code rev what is tc log?
// fibonacci
// ap gp segmeneted sive