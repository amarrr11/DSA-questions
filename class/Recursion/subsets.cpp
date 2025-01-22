/*generate subsets*/
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(string s,string temp,int idx){
    if(idx==s.size()){
        ans.push_back(temp);
        return ;
    }

    solve(s,temp,idx+1);
    temp.push_back(s[idx]);
    solve(s,temp,idx+1);

}

int main(){
    
    string s="abc";

    solve("abc","",0);
    for(auto& s:ans){
        cout<<s<<endl;
    }

}