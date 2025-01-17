/*longest substring with all distict characters*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="abcdabcde";
    int i=0;
    int j=0;
    int n=s.size();
    unordered_map<char,int> mp;
    int start=0;
    string ans="";

    int maxi=0; 
    while(j<n){   
        // start=i;
        mp[s[j]]++;
        while(i<j and mp[s[i]]>1){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(mp[s[i]]);
            i++;
        }
        // while(j<n and mp[s[j]]==0){
        //     mp[s[j]]++;
        //     j++;
            if(j-i+1>maxi){
                maxi=j-i+1;
                ans=s.substr(i,maxi);
            }
        // }
        j++;
        
    }
    // cout<<s.substr(start,maxi)<<endl;
    cout<<ans<<endl;

}