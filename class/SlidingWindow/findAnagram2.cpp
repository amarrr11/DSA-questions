
/*Given a string and a pattern find occurences of pattern or its permuations in the string minimumm lenght substring*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="xyzdaacllabcdadfeubcda";
                //  i   j
    string pattern="abcd";
    int n=s.size();
    int maxi=0;
    int j=0;
    string ans="";
    int i=0;

    unordered_map<char,int> mp;
    for(char &ch:pattern) mp[ch]++;

    while(j<s.size()){
        while(mp.count(s[j])==0 and j<n){
            i++;
            j++;
        }
        
        while(mp.count(s[j])==1 and j<n){
            j++;
        }
        
        if(j-i>maxi){
            maxi=j-i;
            ans=s.substr(i,maxi);
        }
        j++;
        i=j;
    }
     cout<<ans<<endl;

}
