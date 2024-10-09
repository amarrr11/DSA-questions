/*

TC: O(logn)

always stored in 1-based indexing as 0th one is reserved

If the heap were 0-indexed, these formulas would become:

Parent of node i is at index (i-1)/2.
Left child of node i is at index 2*i + 1.
Right child of node i is at index 2*i + 2

If node at ith index
    -left child at 2*i
    -right child at 2*i+1
    -to find parent - i/2
*/

#include<bits/stdc++.h>
using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){

        size=size+1; //jisme insert krna h waha jao
        int index=size;
        arr[index]=val;

        while(index>1) {
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return ;
            }
        }
    }

    print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    return 0;

}