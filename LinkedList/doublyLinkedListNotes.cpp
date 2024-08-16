#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data=value;
        next=prev=NULL;
    }
};

int main(){

     //create doubly linked list
    
    Node *head=NULL,*tail=NULL;

    
    int arr[]={1,2,3,4,5};

    for(int i=0;i<5;i++){
        //if head doesn't exist
        if(head==NULL){
            head=new Node(arr[i]);
            tail=head;
        }
        else{
            Node* temp=new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }

    //insert at start

    //linkedlist doesnt exist

    if(head==NULL){
        head=new Node(5);
    }
    else{
        Node *temp=new Node(5);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
    
    //insert at an given position
    int pos=5;

    //insert at start
    if(pos==0){
        //linkedlist exist na kre
        if(head==NULL){
            head=new Node(5);
        }
        //exist krti
        else{
            Node* temp=new Node(5);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    else{
        Node* curr=head;
        //go to the node after which i have to insert
        while(--pos){
            curr=curr->next;
        }

        //insert at end
        if(curr->next==NULL) {
            Node *temp=new Node(5);
            temp->prev=curr;
            curr->next=temp;
        }
        //insert at middle
        else{
            Node* temp=new Node(5);
            temp->next=curr->next;
            temp->prev=curr;
            curr->next=temp;
            temp->next->prev=temp;
         }

    }

    Node *trav=head;
    while(trav){
        cout<<trav->data<<" ";
        trav=trav->next;
    }
    

}