/*Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string input)
{
    int n=input.size();
    string s="";

    reverse(input.begin(),input.end());

    string temp="";
    int a=0,b=0;
    while(b<=n){
        if(b==n){
            reverse(temp.begin(),temp.end());
            s+=temp;
            break;
        }
        if(input[b]==' '){
            reverse(temp.begin(),temp.end());
            s+=temp;
            s+=" ";
            temp="";
            b++;
        }
        
        temp+=input[b];

        b++;
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}