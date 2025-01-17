/*0's and 1's strig gven find longest substring with all 1s at most k 0's replace*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="110101001101111";
    int k=2;
    int n=s.size();
    string ans="";
    int i=0,j=0;
    int o=0,z=0;
    int maxi=0;
    while(j<n){
        if(s[j]=='1') o++;
        else z++;
        
        if(j-i+1 - o >k){
            while(i<j and z>k){
                if(s[i]=='1') o--;
                else z--;
                i++;
            }
        }
        
        if(j-i+1>maxi){
            maxi=j-i+1;
            ans=s.substr(i,maxi);
        }
        j++;
    }
    cout<<ans<<endl;
}