// A palindrome is a string that reads the same in both directions, for example z, uwu, or moom.

// Input
// The first line contains an integer t
//  (1≤t≤100
// ) — the number of testcases.

// The following t
//  lines each contain a string of length at most 100
//  consisting of lowercase English letters.

// Output
// For each test case, output "YES" or "NO", denoting the answer.

#include<iostream>

using namespace std;
bool palindrome(string &str){
    int s=0;
    int e=str.length()-1;
    if(str.length()<=2){
        return 1;
    }
    while(s<e){
        if(str[s++]!=str[e--]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    string *arr=new string[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(palindrome(arr[i])){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}