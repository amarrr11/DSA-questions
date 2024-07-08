#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //LPF:
    int maxi=*max_element(arr.begin(),arr.end());
    vector<int> LPF(maxi+1,-1);
    vector<int> prime(maxi+1,1);

    for(int i=2;i<=maxi;i++){
        if(prime[i]){
            LPF[i]=i;
            for(int j=2*i;j<=maxi;j+=i){
                prime[j]=0;
                if(LPF[j]==-1){
                    LPF[j]=i;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<LPF[arr[i]]<<" ";
    }
    
    
    
}