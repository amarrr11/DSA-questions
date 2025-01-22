/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2*/

#include<bits/stdc++.h>
using namespace std;

void insertAtSortPosition(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    if(val <= s.top()){
        s.push(val);
        return ;
    }

    int topVal=s.top();
    s.pop();
    insertAtSortPosition(s,val);
    s.push(topVal);
}

void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int val=s.top();
    s.pop();
    sort(s);
    insertAtSortPosition(s,val);
}

int main(){
    stack<int> s;
    
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(4);
    s.push(41);

    sort(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}