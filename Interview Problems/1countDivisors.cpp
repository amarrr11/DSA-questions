#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    //all divisors of a vector of numbers 
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans(n);
    
    int m=*max_element(arr.begin(),arr.end());
    for(int i=1;i<=m;i++){
        for(int j=2*i;j<=m;j+=i){
            ans[j].push_back(i);
        }
    }
    for(auto i:arr){
        for(auto j:ans[i]){
            cout<<j<<" ";
        }
    }

    return 0;
}