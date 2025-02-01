/*Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 621K+Points: 4
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is 
already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.*/

#include<bits/stdc++.h>
using namespace std;

int cnt=0;
void merge(vector<int> &v,int low,int mid,int high){
    vector<int> ans;
    int left=low;
    int right=mid+1;
    while(left<=mid and right<=high){
        if(v[left]<v[right]){
            ans.push_back(v[left++]);
        }else{
            //right is smaller
            cnt+=(mid-left+1);
            ans.push_back(v[right++]);
        }
    }
    while(left<=mid){
        ans.push_back(v[left++]);
    }
    while(right<=high){
        ans.push_back(v[right++]);
    }
    for (int i = 0; i < ans.size(); i++) {
        v[i] = ans[i];
    }
}

void solve(vector<int> &v,int low,int high){
    if(low>=high) return;

    int mid=(low+high)/2;
    solve(v,low,mid);
    solve(v,mid+1,high);
    merge(v,low,mid,high);
}

int main(){
    vector<int> v={3,2,1,5,3,77,8,7,6};
    solve(v,0,v.size()-1);
    // for(int &i:v){
    //     cout<<i<<" ";
    // }
    cout<<cnt<<endl;
    return 0;
}