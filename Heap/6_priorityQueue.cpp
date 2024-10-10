#include<bits/stdc++.h>
using namespace std;

int main(){
//max heap by default
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top "<<pq.top()<<endl;
    pq.pop();

    cout<<"Element at top "<<pq.top()<<endl;



    //min heap
    priority_queue<int, vector<int> ,greater<int>  > minheap;

    minheap.push(4); 
    minheap.push(2); 
    minheap.push(5); 
    minheap.push(3); 

    cout<<"Element at top "<<minheap.top()<<endl;
    minheap.pop();

    cout<<"Element at top "<<minheap.top()<<endl;


    return 0;
}