#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    string sm="",bg="";
    for(int i=0;i<s.size();i++){
        if(islower(s[i])){
            sm+=s[i];
        }else{
            bg+=s[i];
        }
    }
    sort(sm.begin(),sm.end());
    sort(bg.begin(),bg.end());
    
    int i=0,j=0;
    for(char &c:s){
        if(islower(c)) c=sm[i++];
        else c=bg[j++];
    }
    cout<<s<<endl;
}