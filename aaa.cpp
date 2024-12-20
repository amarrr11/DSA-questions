#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={8,2,3,3,5,5,7,7,7,6,6,6};
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int maxi=0;
    for(auto &it:mp){
        if(it.second>1){
            maxi=max(maxi,it.first);
        }
    }
    cout<<maxi<<endl;
}