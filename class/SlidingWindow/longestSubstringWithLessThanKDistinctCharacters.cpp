/* Given string s , find longest substring which can have no more than k distinct characters */

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s= "ufhuuhhfuwhf";
    int k=3;
    int n=s.size();
    unordered_map<char,int> mp;
    int start=0;
    int size=0;
    int maxi=0;
    int i=0;
    int j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<=k){
            if(j-i+1>maxi){
                maxi=j-i+1;
                start=i;
                size=j-i+1;
            }
        }else{
            while(mp.size()>k and i<j){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    cout<<start<<endl;
    cout<<size<<endl;
    cout<<s.substr(start,size)<<endl;
    return 0;
}