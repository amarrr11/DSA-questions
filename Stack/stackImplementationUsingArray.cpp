#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

    public:

    //constructor
    Stack(int s)
    {
        size=s;
        top=-1;
        arr=new int[s];
    }

    //push
    void push(int value)
    {
        if(top==size-1)
        {
            cout<<"Stack overflow\n";
            return ;
        }
        else
        {
            top++;
            arr[top]=value;
            cout<<"Pushed "<<value<<" into the stack\n";
        }
    }

    //pop
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack Underflowed\n";
        }
        else
        {
            top--;
            cout<<"popped "<<arr[top+1]<<" succesfully\n";
        }
    
    }
    
    //peek

    int peek()
    {
        if(top==-1)
        {
            cout<<"stack is empty\n";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    
    //isEmpty

    bool isEmpty()
    {
        return top==-1;
    }

    //issize

    int isSize()
    {
        return top+1;
    }
};
int main()
{
    Stack s(5);
    s.push(5);
    s.push(3);
    s.push(1);
    s.pop();
    cout<<s.isSize()<<endl;
}