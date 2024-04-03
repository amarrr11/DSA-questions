// You are given three digits a
// , b
// , and c
// . Determine whether they form a stair, a peak, or neither.

// A stair satisfies the condition a<b<c
// .
// A peak satisfies the condition a<b>c
// .

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> input(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>input[i][0];
        cin>>input[i][1];
        cin>>input[i][2];
    }
    for(int i=0;i<n;i++){
        int a=input[i][0];
        int b=input[i][1];
        int c=input[i][2];
        if(a<b && b<c){
            cout<<"STAIR"<<endl;
            
        }
        else if(a<b && b>c){
            cout<<"PEAK"<<endl;
            
        }
        else{
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}