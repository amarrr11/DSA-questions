#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

class Stack
{
    Node *top;
    int size; //actual size of stack

    public:

    Stack()
    {
        top=NULL;
        size=0;
    }
    //push
    void push(int value)
    {
        Node *temp=new Node(value);
        if(temp==NULL)
        {
            cout<<"stack overflow\n";
            return;
        }
        else
        {
            temp->next=top;
            top=temp;
            size++; 
            
        }
    }

    //pop
void pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow\n";
        return;
    }
    else
    {
        Node *temp=top;
        cout<<"popped "<<top->data<<" from the stack\n";
        top=top->next;
        delete temp;
        size--;
    }
}
    //peek

    int peek()
    {
        if(top==NULL)
        {
            cout<<"stack is empty\n";
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    //isempty

    bool isEmpty()
    {
        return top==NULL;
    }

    //issize

    int isSize()
    {
        return size;
    }

};

int main()
{
    Stack s;
    s.push(23);
    s.push(34);
    s.push(3);
    s.push(2);
    cout<< s.isSize()<<endl;
}
