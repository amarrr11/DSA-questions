#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int low,int mid,int high){
    vector<int> ans;
    int left=low;
    int right=mid+1;
    while(left<=mid and right<=high){
        if(v[left]<v[right]){
            ans.push_back(v[left++]);
        }else{
            ans.push_back(v[right++]);
        }
    }
    while(left<=mid){
        ans.push_back(v[left++]);
    }
    while(right<=high){
        ans.push_back(v[right++]);
    }
    for (int i = 0; i < ans.size(); i++) {
        v[i] = ans[i];
    }
}

void solve(vector<int> &v,int low,int high){
    if(low>=high) return;

    int mid=(low+high)/2;
    solve(v,low,mid);
    solve(v,mid+1,high);
    merge(v,low,mid,high);
}

int main(){
    vector<int> v={3,2,1,5,3,77,8,7,6};
    solve(v,0,v.size()-1);
    for(int &i:v){
        cout<<i<<" ";
    }
    return 0;
}