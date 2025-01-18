/*
Find range of starting and ending of a number
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={ 1,2 ,3,4,4,5,5,5,6,6,8};

    int n=v.size();
    int start=0;
    int end=n-1;

    int target=4;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(v[mid]>=target){
            start=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<start<<endl;

    //upper bound
    low=0;
    high=n-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(v[mid]>target){  //not equal to / not last occurence
            end=mid;
            high=mid-1;
            
        }else{
            low=mid+1;
        }
    }
    cout<<end<<endl;
}