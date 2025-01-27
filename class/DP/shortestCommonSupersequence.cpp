#include<bits/stdc++.h>
using namespace std;

int solve(string &a,string &b,int i,int j){

    if(i==a.size() or j==b.size()){
        return 0;
    }

    if(a[i]==b[j]){
        return 1+solve(a,b,i+1,j+1);
    }else{
        return max(solve(a,b,i,j+1),solve(a,b,i+1,j));
    }
}

int main(){

    string a="lbcm";
    string b="abco";

    cout<<a.size() + b.size() - solve(a,b,0,0)<<endl;
}