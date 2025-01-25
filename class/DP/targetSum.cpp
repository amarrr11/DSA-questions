#include<bits/stdc++.h>
using namespace std;

solve(vector<int> &nums,int i,int target){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    return solve(nums,i+1,target-nums[i]) or solve(nums,i+1,target+nums[i]);
}

int main(){

    vector<int> v={}

}