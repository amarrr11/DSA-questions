#include<bits/stdc++.h>
using namespace std;
int main(){
    char alpha;
    cin>>alpha;
    char mask=1<<5;
    int res=alpha&mask;
    if(res==0){
        cout<<"UPPER"<<endl; 

    }else{
        cout<<"LOWER"<<endl;
    }
    //A 65 0100 0001
    //a 97 0110 0001
    //mask 0010 0000

    //to check if upper or lower;

    char ans = alpha ^ mask; //need to toggle
    cout<< ans <<endl;
}
