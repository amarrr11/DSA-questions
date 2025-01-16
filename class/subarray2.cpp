/* Given string s , find longest substring which can have no more than k distinct characters */

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s= "asbcdsaebswuqbas";
    int k=4;
    int n=s.size();
    unordered_map<char,int> mp;
    string ans="";
    int i=0;
    int j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<=k){
            if(j-i+1>maxi){
                maxi=j-i+1;
                ans=s.substr(i,maxi);
            }
        }else{
            while(mp.size()>k and i<j){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase();
                i++;
            }
        }
        j++;
    }
    cout<<ans<<endl;
}