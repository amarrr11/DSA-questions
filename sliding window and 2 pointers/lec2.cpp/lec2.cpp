/* MAXIMUM POINTS YOU CAN OBTAIN FROM CARDS */
//Given an array of integers and a value k, you can take values from beginning or from end with total of k values give the maximum sum

#include<iostream>
using namespace std;
int main(){
    int arr[]={6,2,3,4,7,2,1,7,1};
    int k=4;
    int n= sizeof(arr)/sizeof(arr[0]);
  
    int lsum=0;
    int rsum=0;
    int sum=0;
    int maxSum=0;

    for(int i=0;i<k;i++){
        lsum+=arr[i];
    }
    maxSum=lsum;
    int r=n-1;
    for(int i=k-1;i>=0;i--){
        lsum=lsum-arr[i];
        rsum=rsum+arr[r];
        sum=lsum+rsum;
        maxSum=max(maxSum,sum);
        r-=1;
    }
    cout<< "The maxSum value is "<<maxSum<<endl;
}