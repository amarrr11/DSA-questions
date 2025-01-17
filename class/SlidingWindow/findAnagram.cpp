/*Given a string and a pattern find all occurences of pattern or its permuations in the string*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="xyzdaacllabcdfeubcda";
    vector<string> ans;
    string pattern="abcd";

    unordered_map<char,int> mp;
    for(char &ch:pattern){
        mp[ch]++;
    }
    unordered_map<char,int> mp1;
    for(int i=0;i<pattern.size();i++){
        mp1[s[i]]++;
    }
    if(mp==mp1){
        ans.push_back(s.substr(0,pattern.size()));
    }
    int j=pattern.size();
    int i=0;
    while(j<s.size()){
        mp1[s[j]]++;
        mp1[s[i]]--;
        if(mp[s[i]]==0) mp.erase(mp[s[i]]);
        if(mp==mp1){
            ans.push_back(s.substr(i+1,pattern.size()));
        }
        j++,i++;
    }
    for(auto &x:ans){
        cout<<x<<" ";
    }

}
