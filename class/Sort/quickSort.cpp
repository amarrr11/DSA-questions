#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int>&arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){

    }
}

void quickSort(vector<int> &arr,int low,int high){
    if(low<high){
        int part=partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
    }
}

int main(){
    
}

// avg case 
// TC: O(nlogn)
// SC: O(nlogn)