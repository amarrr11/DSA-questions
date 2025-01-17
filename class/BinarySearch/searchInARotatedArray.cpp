#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={3,4,5,6,1,2};
    int n=v.size();
    int target=2;
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(v[mid]==target){
            cout<<mid+1<<endl;
            return 0;
        }
        else if(v[start]<=v[mid]){
            if(target>=v[start] and target<=v[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(target>=v[mid] and target<=v[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }

    return 0;
}