/* Reverse a stack without using any other data structure */

#include<bits/stdc++.h>
using namespace std;

void func(stack<int> &s){
    if(s.empty()){
        
    }
    s.pop();
    func(s);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    while(!s.empty()){
        func(s);
    }

    
    
}