//contiguous elements.
//1 2 3 - {},{1},{2},{3},{1,2},{2,3},{1,2,3}

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v,vector<int> &arr,int n,int idx){

    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    solve(v,arr,n,idx+1);

    if(v.size()==0 || arr[idx-1]==v[v.size()-1]){
        v.push_back(arr[idx]);
        solve(v,arr,n,idx+1);
    }

}

int main()
{
    // int arr[]={1,2,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         for(int k=i;k<=j;k++){
    //             cout<<arr[k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    vector<int> arr={1,2,3,4};
    vector<int> v;
    int n=arr.size();
    solve(v,arr,n,0);
}