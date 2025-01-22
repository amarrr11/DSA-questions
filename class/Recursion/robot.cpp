#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,int n,int m){
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(i>=n or j>=m){
        return 0;
    }

    return (solve(i+1,j,n,m)+solve(i,j+1,n,m));
}

int main(){
    int n=3;
    int m=4;

    cout<<solve(0,0,n,m)<<endl;

}
