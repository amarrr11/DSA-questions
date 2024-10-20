#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n;
        cin>>k;
        vector<long long> v(k);
        
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(v[i]==k){
                cout<<v[i]<<endl;
                flag=false;
                break;
            }
        }
        if(!flag) continue;
        int press=0;
        
        sort(v.begin(),v.end(),greater<int>());
        for(int i:v){
            press+=i;
            if(press>k){
                break;
            }
        }
        if(press-1==k){
            cout<<press<<endl;
        }else{
            cout<<press-1<<endl;
        }
        
        // while(k){
        //     int cnt=0;
        //     for(int &i:v){
        //         if(i==-1) continue;
        //         if(i==0){
        //             press++;
        //             cnt++;
        //             i=-1;
        //             continue;
        //         }
        //         if(press>k){
        //             cout<<press<<endl;
        //             break;
        //         }
        //         cnt++;
        //         i-=1;
        //         press++;
                
        //     }
        //     k-=cnt;
        // }
        
    }
    

    return 0;
}