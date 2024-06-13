/*
example:
5
2 3 3 4 5
3

The first occ is: 1
The last occ  is : 2

*/

#include <iostream>
#include<vector>
using namespace std;
int first(vector<int> &arr,int low,int high,int k){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            if(mid==0 || arr[mid-1]<k){
                return mid;
                break;
            }
            else if(arr[mid-1]==k){
                // high=mid-1;
                return first(arr,low,mid-1,k);
            }
            
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    return -1;
}
int last(vector<int> &arr,int low,int high,int k){
    int n=arr.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            if(mid==n-1 || arr[mid+1]>k){
                return mid;
                break;
            }
            else if(arr[mid+1]==k){
                // high=mid-1;
                return first(arr,mid+1,high,k);
            }
            
        }
        else if(arr[mid]>k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    return -1;
}

int main() {
    
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   cin>>k;
   cout<<endl;
   
   int a=first(arr,0,n-1,k);
   int b=last(arr,0,n-1,k);
   cout<<"The first occ is: "<<a<<endl;
 
   cout<<"The last occ  is : "<<b<<endl;
     return 0;
}