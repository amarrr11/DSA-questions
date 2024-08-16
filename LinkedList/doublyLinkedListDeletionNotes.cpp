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

    // //delete at start

    // if(head!=NULL){

    //     //if only one node exists
    //     if(head->next==NULL)
    //     {
    //         delete head;
    //         head=NULL;
    //     }
    //     //if more than 1 node exists
    //     else{
    //         Node *temp=head;
    //         head=head->next;
    //         delete temp;
    //         head->prev=NULL;
    //     }

    // }

    // //delete at end

    // if(head!=NULL){
    //     //if only one node exists
    //     if(head->next==NULL)
    //     {
    //         delete head;
    //         head=NULL;
    //     }
    //     else
    //     {
    //         Node *curr= head;
    //         while(curr->next){
    //             curr=curr->next;
    //         }
    //         curr->prev->next=NULL;
    //         delete curr;
    //     }
    // }

    //delete at any position
    int pos=3;

    //delete at start
    if(pos==1){
    //if only one node exists
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
        }
        //if more than 1 node exists
        else{
            Node *temp=head;
            head=head->next;
            delete temp;
            head->prev=NULL;
        }
    }else{
        Node* curr=head;
        while(--pos){
            curr=curr->next;
        }

        //delete at end
        if(curr->next==NULL)
        {
            curr->prev->next=NULL;
            delete curr;
        }

        //delete at any middle
        else
        {
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            delete curr;
        }
    }



    Node *trav=head;
    while(trav){
        cout<<trav->data<<" ";
        trav=trav->next;
    }
    

}