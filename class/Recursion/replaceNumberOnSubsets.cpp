#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
int solve(vector<int> &nums,int target,int idx){
    if(target==0){
        return 0;
    }
    if(target<0){
        return -1;
    }

    int ans=-1;
    for(int &num:nums){
        int ans=solve(nums,target-num);
        if(ans!=-1){
            maxi=max(ans,maxi);
        }
    }
    
    return maxi!=-1?maxi+1:-1;
}

int main(){
    // string s="abc";
    // solve(s,"",0);

    // for(string s:ans){
        // cout<<s<<endl;
    // }

    cout<<
}