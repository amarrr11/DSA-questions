/*You are given a array of positive integers and number k . Find maximum lenght of subarray of sum k */

#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &v,int sum,int n,int k){
    int i=0;
    int j=k;
    int maxi=sum;
    while(j<n){
        sum-=v[i];
        sum+=v[j];
        maxi=max(maxi,sum);
        i++;
        j++;
    }
    return maxi;
}

int main(){
    int n=9;
    vector<int> v={2,3,4,1,7,3,4,6,2};
    int k=3;

    int sum=0;
    for(int i=0;i<k;i++) sum+=v[i];
    int maxi=sum;
    
    cout<<func(v,sum,n,k)<<endl;
}