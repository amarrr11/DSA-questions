/*
Square root of a number by binary search 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=17;

    int low=0;
    int high=n;
    int res=low;
    while(low<=high){
        int mid=low+(high-low)/2;

        int product=mid*mid;
        if(product==n){
            cout<<mid<<endl;
            return 0;
        }else if(product<n){
            res=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<res<<endl;
}