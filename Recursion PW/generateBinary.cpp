/**/

#include<bits/stdc++.h>
using namespace std;

void generate(string s,int n){
    if(n==s.size()){
        cout<<s<<endl;
        return;
    }


    generate(s+'0',n);
    
    if(!s.empty() and s[s.size()-1]!='1'){
        
        generate(s+'1',n);
    }
    
}

int main(){
    int n=4;
    generate("",n);
}