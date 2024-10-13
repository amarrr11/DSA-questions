/*
1.First make it a max heap
2.Swap first and last position 
3.size-- and take the node at first to its correct position using heapify

*/

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){

    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n and arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n and arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){

    int size = n;

    while(size>1){
        //step1: swap
        swap(arr[size],arr[1]);
        size--;

        //step 2
        heapify(arr,size,1);
    }
}

int main(){

    int arr[6]={-1,54,53,55,52,50};
    int n=5;

    //heap creation
    for(int i=n/2-1;i>=1;i--){
        heapify(arr,n,i);
    }

    heapSort(arr,n);

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}