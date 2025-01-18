/*
1 1 3 3 3 4 5 6 
lower bound(3)=2 (index)
upper bound(3)=5

lower bound(2)=2 (index)
upper bound(2)=2
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1, 1, 3, 3, 3, 4, 5, 6 };
    int n=v.size();
    int target=3;
    int res=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>=target){
            res=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    // if(res==n-1 and target!=v[n-1]){
    //     cout<<-1<<endl;
    // }else{
        cout<<res<<endl;
    // }
    return 0;

}