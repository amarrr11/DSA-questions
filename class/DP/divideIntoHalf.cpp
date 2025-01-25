#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums,int target,int i){
    if(i>=nums.size()){
        return 0;
    }
    if(target==0){
        return 1;
    }

    return solve(nums,target-nums[i],i+1) or solve(nums,target,i+1);
}

int main(){
    
    vector<int> v={1,2,3,5};
    int sum=accumulate(v.begin(),v.end(),0);
    if(sum&1){
        cout<<"Not possible"<<endl;
        return 0;
    }
    cout<<solve(v,sum/2,0)<<endl;
    return 0;

}